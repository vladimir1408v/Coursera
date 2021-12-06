#include "stdafx.h"
#include <string>
#include "test_runner.h"
using namespace std;

class Editor {
public:
	Editor() {};
	void Left() { if (pos > 0) --pos; }
	void Right() { if (pos < text_.size()) ++pos; };

	void Insert(char token)
	{
		text_.insert(pos, &token);
		Right();
	}

	void Cut(size_t tokens = 1) 
	{
		tokens = CorrectTokensSize(tokens);
		if (tokens > 0)
		{
			Copy(tokens);
			text_.erase(pos, tokens);
		}
	};

	void Copy(size_t tokens = 1) 
	{
		tokens = CorrectTokensSize(tokens);
		if (tokens > 0)
			copy_cut_text_ = text_.substr(pos, tokens);
	};

	void Paste() 
	{
		if (copy_cut_text_.size())
		{
			text_.insert(pos, copy_cut_text_);
			pos += copy_cut_text_.size();
		}
	};

	string GetText() const
	{
		return text_;
	};

private:
	size_t CorrectTokensSize(size_t tokens)
	{
		size_t tokens_ = tokens;
		size_t size_from_pos = text_.size() - pos;
		if (size_from_pos < tokens_)
			tokens_ = size_from_pos;

		return tokens_;
	};

private:
	string text_ = "";
	string copy_cut_text_ = "";
	size_t pos = 0;
};

void TypeText(Editor& editor, const string& text) {
	for (char c : text) {
		editor.Insert(c);
	}
}

void TestEditing() {
	{
		Editor editor;

		const size_t text_len = 12;
		const size_t first_part_len = 7;
		TypeText(editor, "hello, world");
		for (size_t i = 0; i < text_len; ++i) {
			editor.Left();
		}
		editor.Cut(first_part_len);
		for (size_t i = 0; i < text_len - first_part_len; ++i) {
			editor.Right();
		}
		TypeText(editor, ", ");
		editor.Paste();
		editor.Left();
		editor.Left();
		editor.Cut(3);

		ASSERT_EQUAL(editor.GetText(), "world, hello");
	}
	{
		Editor editor;

		TypeText(editor, "misprnit");
		editor.Left();
		editor.Left();
		editor.Left();
		editor.Cut(1);
		editor.Right();
		editor.Paste();

		ASSERT_EQUAL(editor.GetText(), "misprint");
	}
}

void TestReverse() {
	Editor editor;

	const string text = "esreveR";
	for (char c : text) {
		editor.Insert(c);
		editor.Left();
	}

	ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
	Editor editor;
	ASSERT_EQUAL(editor.GetText(), "");

	editor.Left();
	editor.Left();
	editor.Right();
	editor.Right();
	editor.Copy(0);
	editor.Cut(0);
	editor.Paste();

	ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
	Editor editor;

	editor.Paste();
	TypeText(editor, "example");
	editor.Left();
	editor.Left();
	editor.Paste();
	editor.Right();
	editor.Paste();
	editor.Copy(0);
	editor.Paste();
	editor.Left();
	editor.Cut(0);
	editor.Paste();

	ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestEditing);
	RUN_TEST(tr, TestReverse);
	RUN_TEST(tr, TestNoText);
	RUN_TEST(tr, TestEmptyBuffer);

	system("PAUSE");
	return 0;
}
