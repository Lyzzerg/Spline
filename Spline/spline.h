#include "TSpline.h"
#include <Windows.h>

#pragma once

namespace Spline {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::string SystemToStl(String ^s) // Перевод типа String ^ в тип string
	{
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		return std::string(ptr);
	};

	/// <summary>
	/// Summary for spline
	/// </summary>
	public ref class spline : public System::Windows::Forms::Form
	{
	public:
		spline(void)
		{
			InitializeComponent();
			graphic = this->CreateGraphics();
			this->funcChart->Visible = false;
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TextBox^  change_step;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  eps;

	private: System::Windows::Forms::Label^  label6;
	private: double step_ch, leftBound, rightBound, expected_epsilon;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~spline()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: Graphics ^graphic;
	private: System::Windows::Forms::ToolStripMenuItem^  generalToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  funcChart;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  rb;
	private: System::Windows::Forms::TextBox^  lb;
	private: System::Windows::Forms::TextBox^  points;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  error_value;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->generalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->funcChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->eps = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->change_step = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->rb = (gcnew System::Windows::Forms::TextBox());
			this->lb = (gcnew System::Windows::Forms::TextBox());
			this->points = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->error_value = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->funcChart))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->generalToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(844, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// generalToolStripMenuItem
			// 
			this->generalToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->generalToolStripMenuItem->Name = L"generalToolStripMenuItem";
			this->generalToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->generalToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &spline::exitToolStripMenuItem_Click);
			// 
			// funcChart
			// 
			chartArea2->Name = L"ChartArea1";
			this->funcChart->ChartAreas->Add(chartArea2);
			this->funcChart->Cursor = System::Windows::Forms::Cursors::Default;
			legend2->Name = L"Legend1";
			this->funcChart->Legends->Add(legend2);
			this->funcChart->Location = System::Drawing::Point(311, 27);
			this->funcChart->Name = L"funcChart";
			this->funcChart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SemiTransparent;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legend1";
			series3->Name = L"Specified function";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"Spline";
			this->funcChart->Series->Add(series3);
			this->funcChart->Series->Add(series4);
			this->funcChart->Size = System::Drawing::Size(521, 387);
			this->funcChart->TabIndex = 1;
			this->funcChart->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->eps);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->change_step);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->rb);
			this->groupBox1->Controls->Add(this->lb);
			this->groupBox1->Controls->Add(this->points);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 160);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Params";
			// 
			// eps
			// 
			this->eps->Location = System::Drawing::Point(94, 126);
			this->eps->Name = L"eps";
			this->eps->Size = System::Drawing::Size(100, 20);
			this->eps->TabIndex = 10;
			this->eps->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 129);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Epsilon";
			// 
			// change_step
			// 
			this->change_step->Location = System::Drawing::Point(94, 98);
			this->change_step->Name = L"change_step";
			this->change_step->Size = System::Drawing::Size(100, 20);
			this->change_step->TabIndex = 8;
			this->change_step->Text = L"0";
			this->change_step->TextChanged += gcnew System::EventHandler(this, &spline::change_step_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 101);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Step of change";
			// 
			// rb
			// 
			this->rb->Location = System::Drawing::Point(94, 72);
			this->rb->Name = L"rb";
			this->rb->Size = System::Drawing::Size(100, 20);
			this->rb->TabIndex = 5;
			this->rb->Text = L"0";
			this->rb->TextChanged += gcnew System::EventHandler(this, &spline::rb_TextChanged);
			// 
			// lb
			// 
			this->lb->Location = System::Drawing::Point(94, 45);
			this->lb->Name = L"lb";
			this->lb->Size = System::Drawing::Size(100, 20);
			this->lb->TabIndex = 4;
			this->lb->Text = L"0";
			this->lb->TextChanged += gcnew System::EventHandler(this, &spline::lb_TextChanged);
			// 
			// points
			// 
			this->points->Location = System::Drawing::Point(94, 19);
			this->points->Name = L"points";
			this->points->Size = System::Drawing::Size(100, 20);
			this->points->TabIndex = 3;
			this->points->Text = L"0";
			this->points->TextChanged += gcnew System::EventHandler(this, &spline::points_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Right Bound";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Left Bound";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Quantity of points";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 239);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Error:";
			// 
			// error_value
			// 
			this->error_value->AutoSize = true;
			this->error_value->Location = System::Drawing::Point(56, 239);
			this->error_value->Name = L"error_value";
			this->error_value->Size = System::Drawing::Size(60, 13);
			this->error_value->TabIndex = 4;
			this->error_value->Text = L"no function";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(218, 46);
			this->button1->Name = L"button1";
			this->button1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button1->Size = System::Drawing::Size(34, 20);
			this->button1->TabIndex = 5;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &spline::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button2->Location = System::Drawing::Point(268, 46);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(37, 20);
			this->button2->TabIndex = 6;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &spline::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button3->Location = System::Drawing::Point(218, 72);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(34, 20);
			this->button3->TabIndex = 7;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &spline::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button4->Location = System::Drawing::Point(218, 99);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(34, 20);
			this->button4->TabIndex = 8;
			this->button4->Text = L"+";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &spline::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button5->Location = System::Drawing::Point(268, 72);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(37, 20);
			this->button5->TabIndex = 9;
			this->button5->Text = L"-";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &spline::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button6->Location = System::Drawing::Point(268, 99);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(37, 20);
			this->button6->TabIndex = 10;
			this->button6->Text = L"-";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &spline::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button7->Location = System::Drawing::Point(12, 375);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(129, 39);
			this->button7->TabIndex = 11;
			this->button7->Text = L"Generate Default";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &spline::button7_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 268);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(293, 101);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button8->Location = System::Drawing::Point(176, 375);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(129, 39);
			this->button8->TabIndex = 13;
			this->button8->Text = L"Find Spline";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &spline::button8_Click);
			// 
			// spline
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(844, 426);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->error_value);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->funcChart);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"spline";
			this->Text = L"spline";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->funcChart))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void drawToolStripMenuItem_Click()
	{
		if (leftBound >= rightBound) {
			rightBound = leftBound + step_ch;
		}
		this->funcChart->Series["Specified function"]->Points->Clear();
		for (double i = leftBound; i < rightBound; i += 1e-2)
			this->funcChart->Series["Specified function"]->Points->AddXY(i, calculateFunction(i));
		this->funcChart->Visible = true;
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Close();
	}

	private: System::Void drawSplineToolStripMenuItem_Click() {
		funcChart->Series["Spline"]->Points->Clear();

		int pointsCount = atoi(SystemToStl(points->Text).c_str());
		if (pointsCount == NULL || pointsCount == 0)
			pointsCount = 2;
		if (pointsCount < 2)
			pointsCount = 2;

		points->Text = pointsCount.ToString();

		double step = (rightBound - leftBound) / pointsCount;

		double *xCoords = new double[pointsCount + 1];
		double *yCoords = new double[pointsCount + 1];
		for (int i = 0; i < pointsCount; i++)
		{
			xCoords[i] = leftBound + (double)i * step;
			yCoords[i] = calculateFunction(xCoords[i]);
		}

		xCoords[pointsCount] = rightBound;
		yCoords[pointsCount] = calculateFunction(xCoords[pointsCount]);

		TSpline spline;
		spline.buildSplines(xCoords, yCoords, pointsCount);

		for (double x = leftBound; x < rightBound; x += 1e-2)
		{
			funcChart->Series["Spline"]->Points->AddXY(x, spline.getInterpolatedFunctionValue(x));
		}

		double epsilon = 0.0;
		int n = 0;
		for (double x = leftBound; x < rightBound; x += step)
		{
			epsilon += abs(calculateFunction(x + step / 2.0) - spline.getInterpolatedFunctionValue(x + step / 2.0));
			n++;
		}

		error_value->Text = (epsilon / n).ToString();

		delete[] xCoords;
		delete[] yCoords;
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int pointsCount = atoi(SystemToStl(points->Text).c_str());
		pointsCount++;
		points->Text = pointsCount.ToString();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		int pointsCount = atoi(SystemToStl(points->Text).c_str());
		pointsCount > 2 ? pointsCount-- : pointsCount = pointsCount;
		points->Text = pointsCount.ToString();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		leftBound = strtod(SystemToStl(lb->Text->Replace(',', '.')).c_str(), &endPtr);
		step_ch = abs(strtod(SystemToStl(change_step->Text->Replace(',', '.')).c_str(), &endPtr));
		if (leftBound < rightBound - step_ch)
			leftBound += step_ch;
		else {
			leftBound = rightBound - step_ch;
		}
		lb->Text = leftBound.ToString()->Replace(',', '.');
		drawToolStripMenuItem_Click();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		step_ch = abs(strtod(SystemToStl(change_step->Text->Replace(',', '.')).c_str(), &endPtr));
		leftBound = strtod(SystemToStl(lb->Text->Replace(',', '.')).c_str(), &endPtr);
		if (leftBound <= rightBound - step_ch)
			leftBound -= step_ch;
		else
			leftBound = rightBound - step_ch;
		lb->Text = leftBound.ToString()->Replace(',', '.');
		drawToolStripMenuItem_Click();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		step_ch = abs(strtod(SystemToStl(change_step->Text->Replace(',', '.')).c_str(), &endPtr));
		rightBound = strtod(SystemToStl(rb->Text->Replace(',', '.')).c_str(), &endPtr);
		if (rightBound >= leftBound + step_ch)
			rightBound += step_ch;
		else
			rightBound = leftBound + step_ch;
		rb->Text = rightBound.ToString()->Replace(',', '.');
		drawToolStripMenuItem_Click();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		step_ch = abs(strtod(SystemToStl(change_step->Text->Replace(',', '.')).c_str(), &endPtr));
		rightBound = strtod(SystemToStl(rb->Text->Replace(',', '.')).c_str(), &endPtr);
		if (rightBound > leftBound + step_ch)
			rightBound -= step_ch;
		else {
			rightBound = leftBound + step_ch;
		}
		rb->Text = rightBound.ToString()->Replace(',', '.');
		drawToolStripMenuItem_Click();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		this->pictureBox1->Image = Image::FromFile("spline.png");
		leftBound = -4;
		rightBound = 4;
		step_ch = 1;
		expected_epsilon = 0.01;
		int pointsCount = 2;
		lb->Text = leftBound.ToString();
		rb->Text = rightBound.ToString();
		points->Text = pointsCount.ToString();
		change_step->Text = step_ch.ToString();
		eps->Text = expected_epsilon.ToString();
		drawSplineToolStripMenuItem_Click();
		drawToolStripMenuItem_Click();
	}
	private: System::Void change_step_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		step_ch = abs(strtod(SystemToStl(change_step->Text->Replace(',', '.')).c_str(), &endPtr));
	}
	private: System::Void lb_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		leftBound = strtod(SystemToStl(lb->Text->Replace(',', '.')).c_str(), &endPtr);
		if (leftBound >= rightBound) {
			leftBound = rightBound - step_ch;
			lb->Text = leftBound.ToString()->Replace(',', '.');
		}
		drawToolStripMenuItem_Click();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void rb_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		rightBound = strtod(SystemToStl(rb->Text->Replace(',', '.')).c_str(), &endPtr);
		if (rightBound <= leftBound) {
			rightBound = leftBound + step_ch;
			rb->Text = rightBound.ToString()->Replace(',', '.');
		}
		drawToolStripMenuItem_Click();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void points_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		int pointsCount = atoi(SystemToStl(points->Text).c_str());
		points->Text = pointsCount.ToString();
		drawSplineToolStripMenuItem_Click();
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		char* endPtr;
		double discripancy = strtod(SystemToStl(error_value->Text->Replace(',', '.')).c_str(), &endPtr);
		expected_epsilon = strtod(SystemToStl(eps->Text->Replace(',', '.')).c_str(), &endPtr);
		while (discripancy > expected_epsilon) {
			int pointsCount = atoi(SystemToStl(points->Text).c_str());
			pointsCount++;
			points->Text = pointsCount.ToString();
			drawSplineToolStripMenuItem_Click();
			discripancy = strtod(SystemToStl(error_value->Text->Replace(',', '.')).c_str(), &endPtr);
		}
	}
};
}
