#pragma once

namespace MouseRepeated {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void){
			InitializeComponent();
			
			
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NotifyIcon^ notifyIcon1;
	private: System::Windows::Forms::Button^ bt_exit;
	private: System::Windows::Forms::Button^ bt_roll_up;

	protected:

	protected:

	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->bt_exit = (gcnew System::Windows::Forms::Button());
			this->bt_roll_up = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"Mouse Repeated";
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::notifyIcon1_MouseDoubleClick);
			// 
			// bt_exit
			// 
			this->bt_exit->Location = System::Drawing::Point(13, 338);
			this->bt_exit->Name = L"bt_exit";
			this->bt_exit->Size = System::Drawing::Size(75, 49);
			this->bt_exit->TabIndex = 0;
			this->bt_exit->Text = L"��������� ������";
			this->bt_exit->UseVisualStyleBackColor = true;
			this->bt_exit->Click += gcnew System::EventHandler(this, &MyForm::bt_exit_Click);
			// 
			// bt_roll_up
			// 
			this->bt_roll_up->Location = System::Drawing::Point(94, 338);
			this->bt_roll_up->Name = L"bt_roll_up";
			this->bt_roll_up->Size = System::Drawing::Size(72, 49);
			this->bt_roll_up->TabIndex = 1;
			this->bt_roll_up->Text = L"�������� � ����";
			this->bt_roll_up->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(306, 399);
			this->ControlBox = false;
			this->Controls->Add(this->bt_roll_up);
			this->Controls->Add(this->bt_exit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mouse Repeated";
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void notifyIcon1_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		notifyIcon1->Visible = false;			// ������ ���� ������ �������
		this->ShowInTaskbar = true;				// ���������� ����������� ���� � ������
		WindowState = FormWindowState::Normal;	// ������������� ����
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == FormWindowState::Minimized) {
			this->ShowInTaskbar = false;		// ������ ���� ���� �� ������
			notifyIcon1->Visible = true;		// ������ ���� ������ � ���� ��������
		}

		// ����������� ��� ��������� ���������� � ����
		notifyIcon1->BalloonTipTitle = "Mouse Repeated";
		notifyIcon1->BalloonTipText = "� �������� � ���� � �������� ���� ������.";
		notifyIcon1->ShowBalloonTip(1000);
	}

	private: System::Void bt_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

};
/////////////////////////////////////////////////////////
}
