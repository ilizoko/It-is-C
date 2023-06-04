#pragma once
#include <iostream>
#include <string>
#include <cctype>//для использования isalpha()
using namespace std;
using namespace System;

namespace task330 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 25);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(319, 195);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите предложение";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 310);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(319, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Начать!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 226);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 223);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(207, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Слова, которые состоят из тех же букв";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(12, 239);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(319, 65);
			this->richTextBox2->TabIndex = 5;
			this->richTextBox2->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 345);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void MarshalString(String^ s, wstring& os) {
			using namespace Runtime::InteropServices;
			const wchar_t* chars =
				(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			string str, tmp, temp;
			String^ bstr = Convert::ToString(richTextBox1->Text);
			MarshalString(bstr, str);
			int i = 0;
			//в след. цикле заносим первое слово в переменную tmp
			while (tmp.empty())//пока в переменной нет никакого значения
				if (isalpha(str[i]))//если очередной символ - буква,то
					while (i < str.size() && isalpha(str[i]))//пока не конец строки и пока идут буквы
					{
						tmp.append(1, str[i]);//заносим очередной символ в tmp
						++i;//идем по строке
					}
				else ++i;//иначе, идем дальше по строке
			bool f;//создаем логическую переменную f
			while (i < str.size())//пока счетчик не дошел до конца строки
			{
				if (isalpha(str[i]))//если очередной символ - буква
				{
					f = true;//присваем f значение "истина"
					temp.erase(0, temp.length());//очищаем переменную для хранения слов из строки
					while (i < str.size() && isalpha(str[i]))//пока не конец строки и пока идут буквы
					{
						temp.append(1, str[i]);//формируем слово
						if (tmp.find(str[i]) == -1)//если в первом слове нет какой-либо буквы из слова(по которому в данный момент идем)
							f = false;//присваиваем f значение "ложь"
						++i;//идем по строке
					}
					if (f)//если слово состоит из тех же букв что и первое(которое в tmp)
						//cout << temp << endl;//выводим его
						richTextBox2->Text = gcnew System::String(temp.c_str());
				}
				else ++i;//иначе, идем дальше по строке
			}
		}
	};
}
