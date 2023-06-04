#pragma once
#include <iostream>
#include <string>
#include <cctype>//äëÿ èñïîëüçîâàíèÿ isalpha()
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
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòðóêòîðà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
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
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
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
			this->label1->Text = L"Ââåäèòå ïðåäëîæåíèå";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 310);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(319, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Íà÷àòü!";
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
			this->label3->Text = L"Ñëîâà, êîòîðûå ñîñòîÿò èç òåõ æå áóêâ";
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
			//â ñëåä. öèêëå çàíîñèì ïåðâîå ñëîâî â ïåðåìåííóþ tmp
			while (tmp.empty())//ïîêà â ïåðåìåííîé íåò íèêàêîãî çíà÷åíèÿ
				if (isalpha(str[i]))//åñëè î÷åðåäíîé ñèìâîë - áóêâà,òî
					while (i < str.size() && isalpha(str[i]))//ïîêà íå êîíåö ñòðîêè è ïîêà èäóò áóêâû
					{
						tmp.append(1, str[i]);//çàíîñèì î÷åðåäíîé ñèìâîë â tmp
						++i;//èäåì ïî ñòðîêå
					}
				else ++i;//èíà÷å, èäåì äàëüøå ïî ñòðîêå
			bool f;//ñîçäàåì ëîãè÷åñêóþ ïåðåìåííóþ f
			while (i < str.size())//ïîêà ñ÷åò÷èê íå äîøåë äî êîíöà ñòðîêè
			{
				if (isalpha(str[i]))//åñëè î÷åðåäíîé ñèìâîë - áóêâà
				{
					f = true;//ïðèñâàåì f çíà÷åíèå "èñòèíà"
					temp.erase(0, temp.length());//î÷èùàåì ïåðåìåííóþ äëÿ õðàíåíèÿ ñëîâ èç ñòðîêè
					while (i < str.size() && isalpha(str[i]))//ïîêà íå êîíåö ñòðîêè è ïîêà èäóò áóêâû
					{
						temp.append(1, str[i]);//ôîðìèðóåì ñëîâî
						if (tmp.find(str[i]) == -1)//åñëè â ïåðâîì ñëîâå íåò êàêîé-ëèáî áóêâû èç ñëîâà(ïî êîòîðîìó â äàííûé ìîìåíò èäåì)
							f = false;//ïðèñâàèâàåì f çíà÷åíèå "ëîæü"
						++i;//èäåì ïî ñòðîêå
					}
					if (f)//åñëè ñëîâî ñîñòîèò èç òåõ æå áóêâ ÷òî è ïåðâîå(êîòîðîå â tmp)
						//cout << temp << endl;//âûâîäèì åãî
						richTextBox2->Text = gcnew System::String(temp.c_str());
				}
				else ++i;//èíà÷å, èäåì äàëüøå ïî ñòðîêå
			}
		}
	};
}
