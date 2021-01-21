#pragma once

namespace MouseRepeated {

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
		MyForm(void){
			InitializeComponent();
			
			
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
	private: System::Windows::Forms::NotifyIcon^ notifyIcon1;

	protected:

	protected:

	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->SuspendLayout();
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"Mouse Repeated";
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::notifyIcon1_MouseDoubleClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(306, 254);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mouse Repeated";
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void notifyIcon1_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		notifyIcon1->Visible = false;			// Делаем нашу иконку скрытой
		this->ShowInTaskbar = true;				// Возвращаем отображение окна в панели
		WindowState = FormWindowState::Normal;	// Разворачиваем окно
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == FormWindowState::Minimized) {
			this->ShowInTaskbar = false;		// Прячем наше окно из панели
			notifyIcon1->Visible = true;		// Делаем нашу иконку в трее активной
		}

		// Уведомление что программа свернулась в трей
		notifyIcon1->BalloonTipTitle = "Программа была спрятана";
		notifyIcon1->BalloonTipText = "Я спрятана в трей и продолжу свою работу.";
		notifyIcon1->ShowBalloonTip(3000);
	}

};
/////////////////////////////////////////////////////////
}
