#pragma once

#include <unordered_map>
#include <set>
#include <string>
#include <msclr\marshal_cppstd.h>
 // for msclr::interop::marshal_as
#include <vector>
#include "graph.h"
#include "engine.h"
#include <msclr/marshal_cppstd.h>

using namespace std;
using namespace msclr::interop;

// Include the header file of FileSystemTree if necessary

namespace DSProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    
    /// <summary>
    /// Summary for Graphconnect
    /// </summary>
    public ref class Graphconnect : public System::Windows::Forms::Form
    {
    public:
        FileSystemTree* filesystemtree;

        Graphconnect(void)
        {
            InitializeComponent();
            this->SuspendLayout();
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(700, 473);
            this->Name = L"Graphconnect";
            this->Text = L"Graphconnect";
            string rootPath = "C:\\Users\\user\\Desktop\\first"; // Set the default path
            fileSystemTree = new FileSystemTree(rootPath);
            this->ResumeLayout(false);

            enteredlbl->Visible = false;
            label1->Visible = false;
            label2->Visible = false;
            label3->Visible = false;
            getbar->Visible = false;
            contentbox2->Visible = false;
            textBox1->Visible = false;
            getbtnn->Visible = false;

            
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Graphconnect()
        {
            if (components)
            {
                delete components;
            }
            delete fileSystemTree; 
        }

    private: System::Windows::Forms::Button^ button1;
    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::Label^ enteredlbl;
    private: System::Windows::Forms::TextBox^ getbar;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::ListBox^ contentbox2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Button^ shortestpathbtn;
    private: System::Windows::Forms::Button^ getbtnn;


        FileSystemTree* fileSystemTree;


           graphs* graph;

        graphs getConnectivityGraph() {
            return fileSystemTree->getConnectivityGraph();
        }

        void DrawGraph() {
            Graphics^ g = this->CreateGraphics();

            Color customBlue = Color::FromArgb(0, 150, 255); 
            SolidBrush^ brush = gcnew SolidBrush(customBlue);

            g->Clear(this->BackColor);

            graph = new graphs(getConnectivityGraph());

            int circleRadius = 20;

            unordered_map<string, Point> nodeCoordinates;

            Random^ rand = gcnew Random();

            for (const auto& vertex : graph->mainlist) {
                string file = vertex.data;

                int x = rand->Next(circleRadius, this->ClientSize.Width - circleRadius);
                int y = rand->Next(circleRadius, this->ClientSize.Height - circleRadius);

                nodeCoordinates[file] = Point(x, y);

                g->FillEllipse(brush, x - circleRadius, y - circleRadius, 2 * circleRadius, 2 * circleRadius);

                g->DrawString(gcnew String(file.c_str()), gcnew System::Drawing::Font("Arial", 10), Brushes::Black, x - circleRadius, y - circleRadius);

                for (const auto& edge : vertex.seclist) {
                    string conn = edge.first;
                    if (nodeCoordinates.find(conn) != nodeCoordinates.end()) {
                        Point connCoords = nodeCoordinates[conn];
                        g->DrawLine(Pens::Black, x, y, connCoords.X, connCoords.Y);
                    }
                }
            }
        }


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->enteredlbl = (gcnew System::Windows::Forms::Label());
            this->getbar = (gcnew System::Windows::Forms::TextBox());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->contentbox2 = (gcnew System::Windows::Forms::ListBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->shortestpathbtn = (gcnew System::Windows::Forms::Button());
            this->getbtnn = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Gainsboro;
            this->button1->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(12, 12);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(133, 28);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Click here to build";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Graphconnect::button1_Click);
            // 
            // enteredlbl
            // 
            this->enteredlbl->AutoSize = true;
            this->enteredlbl->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->enteredlbl->Location = System::Drawing::Point(8, 358);
            this->enteredlbl->Name = L"enteredlbl";
            this->enteredlbl->Size = System::Drawing::Size(427, 21);
            this->enteredlbl->TabIndex = 15;
            this->enteredlbl->Text = L"Enter File names to get shortest path in between them";
            // 
            // getbar
            // 
            this->getbar->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->getbar->Location = System::Drawing::Point(441, 354);
            this->getbar->Multiline = true;
            this->getbar->Name = L"getbar";
            this->getbar->Size = System::Drawing::Size(120, 32);
            this->getbar->TabIndex = 20;
            // 
            // textBox1
            // 
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox1->Location = System::Drawing::Point(567, 354);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(120, 32);
            this->textBox1->TabIndex = 21;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(439, 335);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(47, 18);
            this->label1->TabIndex = 22;
            this->label1->Text = L"File 01";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(565, 333);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(49, 18);
            this->label2->TabIndex = 23;
            this->label2->Text = L"File 02";
            // 
            // contentbox2
            // 
            this->contentbox2->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->contentbox2->FormattingEnabled = true;
            this->contentbox2->ItemHeight = 21;
            this->contentbox2->Location = System::Drawing::Point(81, 393);
            this->contentbox2->Margin = System::Windows::Forms::Padding(4);
            this->contentbox2->Name = L"contentbox2";
            this->contentbox2->Size = System::Drawing::Size(519, 25);
            this->contentbox2->TabIndex = 24;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(12, 393);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(62, 21);
            this->label3->TabIndex = 25;
            this->label3->Text = L"Path is";
            // 
            // shortestpathbtn
            // 
            this->shortestpathbtn->BackColor = System::Drawing::Color::Gainsboro;
            this->shortestpathbtn->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->shortestpathbtn->Location = System::Drawing::Point(151, 12);
            this->shortestpathbtn->Name = L"shortestpathbtn";
            this->shortestpathbtn->Size = System::Drawing::Size(108, 28);
            this->shortestpathbtn->TabIndex = 26;
            this->shortestpathbtn->Text = L"Shortest Path";
            this->shortestpathbtn->UseVisualStyleBackColor = false;
            this->shortestpathbtn->Click += gcnew System::EventHandler(this, &Graphconnect::shortestpathbtn_Click);
            // 
            // getbtnn
            // 
            this->getbtnn->BackColor = System::Drawing::Color::Gainsboro;
            this->getbtnn->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->getbtnn->Location = System::Drawing::Point(607, 391);
            this->getbtnn->Name = L"getbtnn";
            this->getbtnn->Size = System::Drawing::Size(80, 28);
            this->getbtnn->TabIndex = 27;
            this->getbtnn->Text = L"Get";
            this->getbtnn->UseVisualStyleBackColor = false;
            this->getbtnn->Click += gcnew System::EventHandler(this, &Graphconnect::button2_Click);
            // 
            // Graphconnect
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(700, 434);
            this->Controls->Add(this->getbtnn);
            this->Controls->Add(this->shortestpathbtn);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->contentbox2);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->getbar);
            this->Controls->Add(this->enteredlbl);
            this->Controls->Add(this->button1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Name = L"Graphconnect";
            this->Text = L"Graph Window (Sumair, Talha, Behzad)";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Redraw the graph
        DrawGraph();
    }
    private: System::Void shortestpathbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        enteredlbl->Visible = true;
        label1->Visible = true;
        label2->Visible = true;
        label3->Visible = true;
        getbar->Visible = true;
        contentbox2->Visible = true;
        textBox1->Visible = true;
        getbtnn->Visible = true;
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string stdfileName1 = msclr::interop::marshal_as<std::string>(getbar->Text);
        std::string stdfileName2 = msclr::interop::marshal_as<std::string>(textBox1->Text);
        string content = graph->BFS(stdfileName1, stdfileName2);
        contentbox2->Items->Clear();
        contentbox2->Items->Add(gcnew String(content.c_str()));
    }

    private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
