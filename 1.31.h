#pragma once

namespace task131
{

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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 44);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(161, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ñòàðò!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ââåäèòå n";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(67, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(177, 82);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ââîä";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnHeader1, this->columnHeader2 });
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 100);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(177, 183);
			this->listView1->TabIndex = 4;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"×èñëî 1";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"×èñëî 2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(200, 295);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//Ôóíêöèÿ ñêàæåò, ïðîñòîå ëè ÷èñëî èëè íåò
		bool isPrime(int n)
		{
			// åñëè n > 1
			if (n > 1)
			{
				// â öèêëå ïåðåáèðàåì ÷èñëà îò 2 äî n - 1
				for (int i = 2; i < n; i++)
					if (n % i == 0) // åñëè n äåëèòñÿ áåç îñòàòêà íà i - âîçâðàùàåì false (÷èñëî íå ïðîñòîå)
						return false;

				// åñëè ïðîãðàììà äîøëà äî äàííîãî îïåðàòîðà, òî âîçâðàùàåì true (÷èñëî ïðîñòîå) - ïðîâåðêà ïðîéäåíà
				return true;
			}
			else // èíà÷å âîçâðàùàåì false (÷èñëî íå ïðîñòîå)
				return false;
		}

		int n; //Êîë-âî ïàð ïðîñòûõ ÷èñåë
		int counter = 0;
		int prev_num = 0, next_num = 1; //Äà
		int i = 0;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			n = Convert::ToInt32(textBox1->Text);
		}
		catch (FormatException^ ex) {
			MessageBox::Show("Íåïðàâèëüíûé ââîä", "Îøèáêà", MessageBoxButtons::OK);
		}
		//Èùåì ïðîñòûå ÷èñëà
		while (counter != n) {
			prev_num++;
			if (isPrime(prev_num) && isPrime(prev_num + 2)) {
				listView1->Items->Add(Convert::ToString(prev_num));
				listView1->Items[i]->SubItems->Add(Convert::ToString(prev_num + 2));
				counter++;
				i++;
			}

		}
	};
	};
}
