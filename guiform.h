#pragma once

#include <msclr/marshal_cppstd.h>
#include <string>
#include <vector>
#include <algorithm>
#include "engine.h"
#include "plotgraphform.h"

bool compareFunction(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return b.second < a.second;
}


namespace DSProject {
    using namespace System;
    using namespace System::ComponentModel;

    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace msclr::interop;



    public ref class guiform : public System::Windows::Forms::Form
    {
    public:
        guiform(void)
        {
            InitializeComponent();
            InitializeFileSystem();
            listBoxResults->Visible = false;
            directoryLbl->Visible = false;
            filenametxt->Visible = true;
            displaybtn->Visible = true;
            contentbox->Visible = false;
            enteredlbl->Visible = false;
            graphlbl->Visible = false;
            graphyesbtn->Visible = false;
            getlbl->Visible = false;
            getbtn->Visible = false;
            getbar->Visible = false;
            contentbox2->Visible = false;
            sugges_display->Visible = false;
            
            originalBackgroundImage = this->BackgroundImage;
        }

    protected:
        ~guiform()
        {
            if (components)
            {
                delete components;
            }
            delete fileSystemTree;
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ textBoxWord;
        System::Windows::Forms::ListBox^ listBoxResults;
    private: System::Windows::Forms::PictureBox^ googlelogo;
    private: System::Windows::Forms::Label^ instructionlbl;

    private: System::Windows::Forms::Label^ directoryLbl;
           System::Drawing::Image^ originalBackgroundImage;


    private: System::Windows::Forms::TextBox^ filenametxt;

    private: System::Windows::Forms::Button^ displaybtn;
    private: System::Windows::Forms::RichTextBox^ contentbox;
    private: System::Windows::Forms::Button^ backbtn;
    private: System::Windows::Forms::Button^ nextbtn;
    private: System::Windows::Forms::Label^ enteredlbl;


           System::Windows::Forms::Button^ buttonSearchWord;
    private: System::Windows::Forms::Label^ graphlbl;
    private: System::Windows::Forms::Button^ graphyesbtn;
    private: System::Windows::Forms::Button^ getbtn;
    private: System::Windows::Forms::Label^ getlbl;


    private: System::Windows::Forms::TextBox^ getbar;
    private: System::Windows::Forms::ListBox^ contentbox2;




           FileSystemTree* fileSystemTree;



#pragma region Windows Form Designer generated code

           String^ imagePath = "G:\\Academics\\DSA\\DS project data\\bg3.PNG";
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::ListBox^ sugges_display;


           Image^ backgroundImage2 = Image::FromFile(imagePath);

           void InitializeComponent(void)
           {
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(guiform::typeid));
               this->textBoxWord = (gcnew System::Windows::Forms::TextBox());
               this->listBoxResults = (gcnew System::Windows::Forms::ListBox());
               this->buttonSearchWord = (gcnew System::Windows::Forms::Button());
               this->googlelogo = (gcnew System::Windows::Forms::PictureBox());
               this->instructionlbl = (gcnew System::Windows::Forms::Label());
               this->directoryLbl = (gcnew System::Windows::Forms::Label());
               this->filenametxt = (gcnew System::Windows::Forms::TextBox());
               this->displaybtn = (gcnew System::Windows::Forms::Button());
               this->contentbox = (gcnew System::Windows::Forms::RichTextBox());
               this->backbtn = (gcnew System::Windows::Forms::Button());
               this->nextbtn = (gcnew System::Windows::Forms::Button());
               this->enteredlbl = (gcnew System::Windows::Forms::Label());
               this->graphlbl = (gcnew System::Windows::Forms::Label());
               this->graphyesbtn = (gcnew System::Windows::Forms::Button());
               this->getbtn = (gcnew System::Windows::Forms::Button());
               this->getlbl = (gcnew System::Windows::Forms::Label());
               this->getbar = (gcnew System::Windows::Forms::TextBox());
               this->contentbox2 = (gcnew System::Windows::Forms::ListBox());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->sugges_display = (gcnew System::Windows::Forms::ListBox());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->googlelogo))->BeginInit();
               this->SuspendLayout();
               // 
               // textBoxWord
               // 
               this->textBoxWord->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->textBoxWord->ForeColor = System::Drawing::Color::Black;
               this->textBoxWord->Location = System::Drawing::Point(187, 303);
               this->textBoxWord->Margin = System::Windows::Forms::Padding(4);
               this->textBoxWord->Multiline = true;
               this->textBoxWord->Name = L"textBoxWord";
               this->textBoxWord->Size = System::Drawing::Size(458, 38);
               this->textBoxWord->TabIndex = 0;
               this->textBoxWord->TextChanged += gcnew System::EventHandler(this, &guiform::textBoxWord_TextChanged);
               // 
               // listBoxResults
               // 
               this->listBoxResults->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->listBoxResults->FormattingEnabled = true;
               this->listBoxResults->ItemHeight = 21;
               this->listBoxResults->Location = System::Drawing::Point(97, 116);
               this->listBoxResults->Margin = System::Windows::Forms::Padding(4);
               this->listBoxResults->Name = L"listBoxResults";
               this->listBoxResults->Size = System::Drawing::Size(692, 235);
               this->listBoxResults->TabIndex = 1;
               this->listBoxResults->SelectedIndexChanged += gcnew System::EventHandler(this, &guiform::listBoxResults_SelectedIndexChanged);
               // 
               // buttonSearchWord
               // 
               this->buttonSearchWord->BackColor = System::Drawing::Color::Transparent;
               this->buttonSearchWord->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonSearchWord.BackgroundImage")));
               this->buttonSearchWord->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
               this->buttonSearchWord->Cursor = System::Windows::Forms::Cursors::Default;
               this->buttonSearchWord->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->buttonSearchWord->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F));
               this->buttonSearchWord->Location = System::Drawing::Point(653, 303);
               this->buttonSearchWord->Margin = System::Windows::Forms::Padding(4);
               this->buttonSearchWord->Name = L"buttonSearchWord";
               this->buttonSearchWord->Size = System::Drawing::Size(39, 38);
               this->buttonSearchWord->TabIndex = 3;
               this->buttonSearchWord->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
               this->buttonSearchWord->UseMnemonic = false;
               this->buttonSearchWord->UseVisualStyleBackColor = false;
               this->buttonSearchWord->Click += gcnew System::EventHandler(this, &guiform::buttonSearchWord_Click);
               // 
               // googlelogo
               // 
               this->googlelogo->BackColor = System::Drawing::Color::Transparent;
               this->googlelogo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"googlelogo.BackgroundImage")));
               this->googlelogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
               this->googlelogo->InitialImage = nullptr;
               this->googlelogo->Location = System::Drawing::Point(353, 180);
               this->googlelogo->Name = L"googlelogo";
               this->googlelogo->Size = System::Drawing::Size(198, 93);
               this->googlelogo->TabIndex = 4;
               this->googlelogo->TabStop = false;
               // 
               // instructionlbl
               // 
               this->instructionlbl->AutoSize = true;
               this->instructionlbl->BackColor = System::Drawing::Color::Transparent;
               this->instructionlbl->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->instructionlbl->Location = System::Drawing::Point(183, 277);
               this->instructionlbl->Name = L"instructionlbl";
               this->instructionlbl->Size = System::Drawing::Size(390, 21);
               this->instructionlbl->TabIndex = 5;
               this->instructionlbl->Text = L"Instruction: Enter word you want to find within files";
               this->instructionlbl->Click += gcnew System::EventHandler(this, &guiform::instructionlbl_Click);
               // 
               // directoryLbl
               // 
               this->directoryLbl->AutoSize = true;
               this->directoryLbl->BackColor = System::Drawing::Color::Transparent;
               this->directoryLbl->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->directoryLbl->Location = System::Drawing::Point(91, 91);
               this->directoryLbl->Name = L"directoryLbl";
               this->directoryLbl->Size = System::Drawing::Size(480, 21);
               this->directoryLbl->TabIndex = 6;
               this->directoryLbl->Text = L"Here are the directories of all those files containing your word";
               // 
               // filenametxt
               // 
               this->filenametxt->BackColor = System::Drawing::Color::White;
               this->filenametxt->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->filenametxt->Location = System::Drawing::Point(146, 21);
               this->filenametxt->Multiline = true;
               this->filenametxt->Name = L"filenametxt";
               this->filenametxt->Size = System::Drawing::Size(675, 38);
               this->filenametxt->TabIndex = 9;
               // 
               // displaybtn
               // 
               this->displaybtn->BackColor = System::Drawing::Color::Transparent;
               this->displaybtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"displaybtn.BackgroundImage")));
               this->displaybtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
               this->displaybtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->displaybtn->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->displaybtn->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
               this->displaybtn->Location = System::Drawing::Point(828, 21);
               this->displaybtn->Name = L"displaybtn";
               this->displaybtn->Size = System::Drawing::Size(39, 38);
               this->displaybtn->TabIndex = 10;
               this->displaybtn->UseVisualStyleBackColor = false;
               this->displaybtn->Click += gcnew System::EventHandler(this, &guiform::displaybtn_Click);
               // 
               // contentbox
               // 
               this->contentbox->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->contentbox->ForeColor = System::Drawing::SystemColors::WindowText;
               this->contentbox->Location = System::Drawing::Point(97, 117);
               this->contentbox->Name = L"contentbox";
               this->contentbox->Size = System::Drawing::Size(692, 165);
               this->contentbox->TabIndex = 11;
               this->contentbox->Text = L"";
               this->contentbox->TextChanged += gcnew System::EventHandler(this, &guiform::richTextBox1_TextChanged);
               // 
               // backbtn
               // 
               this->backbtn->BackColor = System::Drawing::Color::Transparent;
               this->backbtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backbtn.BackgroundImage")));
               this->backbtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
               this->backbtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->backbtn->ForeColor = System::Drawing::SystemColors::ControlText;
               this->backbtn->Location = System::Drawing::Point(62, 21);
               this->backbtn->Name = L"backbtn";
               this->backbtn->Size = System::Drawing::Size(36, 38);
               this->backbtn->TabIndex = 12;
               this->backbtn->UseVisualStyleBackColor = false;
               this->backbtn->Click += gcnew System::EventHandler(this, &guiform::backbtn_Click);
               // 
               // nextbtn
               // 
               this->nextbtn->BackColor = System::Drawing::Color::Transparent;
               this->nextbtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nextbtn.BackgroundImage")));
               this->nextbtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
               this->nextbtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->nextbtn->ForeColor = System::Drawing::SystemColors::ControlText;
               this->nextbtn->Location = System::Drawing::Point(104, 21);
               this->nextbtn->Name = L"nextbtn";
               this->nextbtn->Size = System::Drawing::Size(36, 38);
               this->nextbtn->TabIndex = 13;
               this->nextbtn->UseVisualStyleBackColor = false;
               this->nextbtn->Click += gcnew System::EventHandler(this, &guiform::nextbtn_Click);
               // 
               // enteredlbl
               // 
               this->enteredlbl->AutoSize = true;
               this->enteredlbl->BackColor = System::Drawing::Color::Transparent;
               this->enteredlbl->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->enteredlbl->Location = System::Drawing::Point(94, 91);
               this->enteredlbl->Name = L"enteredlbl";
               this->enteredlbl->Size = System::Drawing::Size(283, 21);
               this->enteredlbl->TabIndex = 14;
               this->enteredlbl->Text = L"Content of your entered directory is";
               this->enteredlbl->Click += gcnew System::EventHandler(this, &guiform::enteredlbl_Click);
               // 
               // graphlbl
               // 
               this->graphlbl->AutoSize = true;
               this->graphlbl->BackColor = System::Drawing::Color::Transparent;
               this->graphlbl->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->graphlbl->Location = System::Drawing::Point(93, 387);
               this->graphlbl->Name = L"graphlbl";
               this->graphlbl->Size = System::Drawing::Size(503, 21);
               this->graphlbl->TabIndex = 15;
               this->graphlbl->Text = L"Do you want to build connectivity graph\? (Press yes to continue)";
               this->graphlbl->Click += gcnew System::EventHandler(this, &guiform::graphlbl_Click);
               // 
               // graphyesbtn
               // 
               this->graphyesbtn->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->graphyesbtn->Location = System::Drawing::Point(712, 382);
               this->graphyesbtn->Name = L"graphyesbtn";
               this->graphyesbtn->Size = System::Drawing::Size(75, 32);
               this->graphyesbtn->TabIndex = 16;
               this->graphyesbtn->Text = L"Yes";
               this->graphyesbtn->UseVisualStyleBackColor = true;
               this->graphyesbtn->Click += gcnew System::EventHandler(this, &guiform::graphyesbtn_Click);
               // 
               // getbtn
               // 
               this->getbtn->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->getbtn->Location = System::Drawing::Point(712, 427);
               this->getbtn->Name = L"getbtn";
               this->getbtn->Size = System::Drawing::Size(75, 32);
               this->getbtn->TabIndex = 18;
               this->getbtn->Text = L"Get";
               this->getbtn->UseVisualStyleBackColor = true;
               this->getbtn->Click += gcnew System::EventHandler(this, &guiform::getbtn_Click);
               // 
               // getlbl
               // 
               this->getlbl->AutoSize = true;
               this->getlbl->BackColor = System::Drawing::Color::Transparent;
               this->getlbl->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->getlbl->Location = System::Drawing::Point(93, 431);
               this->getlbl->Name = L"getlbl";
               this->getlbl->Size = System::Drawing::Size(274, 21);
               this->getlbl->TabIndex = 17;
               this->getlbl->Text = L"Enter File name to get its directory";
               this->getlbl->Click += gcnew System::EventHandler(this, &guiform::label1_Click);
               // 
               // getbar
               // 
               this->getbar->Font = (gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->getbar->Location = System::Drawing::Point(373, 427);
               this->getbar->Multiline = true;
               this->getbar->Name = L"getbar";
               this->getbar->Size = System::Drawing::Size(330, 32);
               this->getbar->TabIndex = 19;
               // 
               // contentbox2
               // 
               this->contentbox2->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->contentbox2->FormattingEnabled = true;
               this->contentbox2->ItemHeight = 21;
               this->contentbox2->Location = System::Drawing::Point(95, 472);
               this->contentbox2->Margin = System::Windows::Forms::Padding(4);
               this->contentbox2->Name = L"contentbox2";
               this->contentbox2->Size = System::Drawing::Size(692, 25);
               this->contentbox2->TabIndex = 20;
               this->contentbox2->SelectedIndexChanged += gcnew System::EventHandler(this, &guiform::listBox1_SelectedIndexChanged);
               // 
               // button1
               // 
               this->button1->BackColor = System::Drawing::Color::Transparent;
               this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
               this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
               this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
               this->button1->Location = System::Drawing::Point(17, 21);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(39, 38);
               this->button1->TabIndex = 21;
               this->button1->UseVisualStyleBackColor = false;
               this->button1->Click += gcnew System::EventHandler(this, &guiform::button1_Click);
               // 
               // sugges_display
               // 
               this->sugges_display->BackColor = System::Drawing::Color::WhiteSmoke;
               this->sugges_display->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->sugges_display->ForeColor = System::Drawing::SystemColors::MenuText;
               this->sugges_display->FormattingEnabled = true;
               this->sugges_display->ItemHeight = 21;
               this->sugges_display->Location = System::Drawing::Point(187, 349);
               this->sugges_display->Margin = System::Windows::Forms::Padding(4);
               this->sugges_display->Name = L"sugges_display";
               this->sugges_display->Size = System::Drawing::Size(505, 130);
               this->sugges_display->TabIndex = 22;
               // 
               // guiform
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::White;
               this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
               this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->ClientSize = System::Drawing::Size(884, 559);
               this->Controls->Add(this->sugges_display);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->contentbox2);
               this->Controls->Add(this->getbar);
               this->Controls->Add(this->getbtn);
               this->Controls->Add(this->getlbl);
               this->Controls->Add(this->graphyesbtn);
               this->Controls->Add(this->graphlbl);
               this->Controls->Add(this->enteredlbl);
               this->Controls->Add(this->nextbtn);
               this->Controls->Add(this->backbtn);
               this->Controls->Add(this->contentbox);
               this->Controls->Add(this->displaybtn);
               this->Controls->Add(this->filenametxt);
               this->Controls->Add(this->directoryLbl);
               this->Controls->Add(this->instructionlbl);
               this->Controls->Add(this->googlelogo);
               this->Controls->Add(this->buttonSearchWord);
               this->Controls->Add(this->listBoxResults);
               this->Controls->Add(this->textBoxWord);
               this->DoubleBuffered = true;
               this->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
               this->Margin = System::Windows::Forms::Padding(4);
               this->Name = L"guiform";
               this->Text = L"Mini Google by (Sumair, Talha, Behzad )";
               this->Load += gcnew System::EventHandler(this, &guiform::guiform_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->googlelogo))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion


           void InitializeFileSystem() {
               fileSystemTree = new FileSystemTree("C:\\Users\\user\\Desktop\\first");
           }


           System::Void buttonSearchWord_Click(System::Object^ sender, System::EventArgs^ e) {
               listBoxResults->Items->Clear(); // Clear the previous results
               sugges_display->Visible = false;
               buttonSearchWord->Visible = false;
               textBoxWord->Visible = false;
               googlelogo->Visible = false;
               instructionlbl->Visible = false;
               directoryLbl->Visible = true;
               enteredlbl->Visible = false;
               graphlbl->Visible = true;
               graphyesbtn->Visible = true;
               listBoxResults->Visible = true; // Show the ListBox
               getlbl->Visible = true;
               getbtn->Visible = true;
               getbar->Visible = true;
               this->BackgroundImage = backgroundImage2;

               String^ word = textBoxWord->Text;
               std::string stdWord = marshal_as<std::string>(word);

               // Define a vector to hold the search results
               std::vector<std::pair<std::string, int>> resultPaths;

               // Call the searchWord function with the entered word and populate the resultPaths vector
               fileSystemTree->searchWord(stdWord, resultPaths);

               if (!resultPaths.empty()) {
                   for (const auto& [path, count] : resultPaths) {
                       listBoxResults->Items->Add(gcnew String((path + " (" + std::to_string(count) + " times)").c_str()));
                   }
               }
               else {
                   listBoxResults->Items->Add("Word not found in any file or directory");
               }
           }





           void sortResults(std::vector<std::pair<std::string, int>>& resultPaths) {
               std::sort(resultPaths.begin(), resultPaths.end(), compareFunction);
           }


    private: System::Void listBoxResults_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBoxWord_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {
        String^ prefix = textBoxWord->Text;
        std::string prefixStr = msclr::interop::marshal_as<std::string>(prefix);

        if(prefixStr==" ") { sugges_display->Visible = false; }

        std::vector<std::string> suggestions = fileSystemTree->getSuggestions(prefixStr);

        sugges_display->Items->Clear();

        for (const auto& suggestion : suggestions) {
            sugges_display->Items->Add(gcnew System::String(suggestion.c_str()));
        }

        sugges_display->Visible = true;
    }

    private: System::Void guiform_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void displaybtn_Click(System::Object^ sender, System::EventArgs^ e) {
        directoryLbl->Visible = false;
        listBoxResults->Visible = false;
        enteredlbl->Visible = false;
        contentbox->Visible = false;
        graphlbl->Visible = false;
        graphyesbtn->Visible = false;
        getlbl->Visible = false;
        getbtn->Visible = false;
        getbar->Visible = false;
        contentbox2->Visible = false;
        contentbox->Visible = true;
        enteredlbl->Visible = true;
        String^ filename = filenametxt->Text;
        std::string stdfileName = marshal_as<std::string>(filename);
        string content = fileSystemTree->displayFileContent(stdfileName);
        contentbox->Text = gcnew String(content.c_str());
    }


    private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void instructionlbl_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void backbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        if (contentbox->Visible)
        {
            this->BackgroundImage = backgroundImage2;
            directoryLbl->Visible = true;
            listBoxResults->Visible = true;
            enteredlbl->Visible = false;
            contentbox->Visible = false;
            graphlbl->Visible = true;
            graphyesbtn->Visible = true;
            getlbl->Visible = true;
            getbtn->Visible = true;
            getbar->Visible = true;
            contentbox2->Visible = true;
        }
        else if (listBoxResults->Visible)
        {
            this->BackgroundImage = originalBackgroundImage;
            buttonSearchWord->Visible = true;
            textBoxWord->Visible = true;
            googlelogo->Visible = true;
            instructionlbl->Visible = true;
            directoryLbl->Visible = false;
            listBoxResults->Visible = false;
            graphlbl->Visible = false;
            graphyesbtn->Visible = false;
            getlbl->Visible = false;
            getbtn->Visible = false;
            getbar->Visible = false;
            contentbox2->Visible = false;

        }



    }
    private: System::Void nextbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        if (googlelogo->Visible)
        {

            this->BackgroundImage = backgroundImage2;
            buttonSearchWord->Visible = false;
            textBoxWord->Visible = false;
            googlelogo->Visible = false;
            instructionlbl->Visible = false;
            directoryLbl->Visible = true;
            listBoxResults->Visible = true;
            graphlbl->Visible = true;
            graphyesbtn->Visible = true;
            getlbl->Visible = true;
            getbtn->Visible = true;
            getbar->Visible = true;
        }
        else if (listBoxResults->Visible)
        {
            this->BackgroundImage = backgroundImage2;
            enteredlbl->Visible = true;
            contentbox->Visible = true;
            directoryLbl->Visible = false;
            listBoxResults->Visible = false;
            graphlbl->Visible = false;
            graphyesbtn->Visible = false;
            getlbl->Visible = false;
            getbtn->Visible = false;
            getbar->Visible = false;
            contentbox2->Visible = false;
        }
        

    }
    private: System::Void graphyesbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        Graphconnect^ pgc = gcnew Graphconnect();
        pgc->Show();
    }
    private: System::Void graphlbl_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void enteredlbl_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void getbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        contentbox2->Visible = true;
        String^ filename = getbar->Text;
        std::string stdfileName = marshal_as<std::string>(filename);
        string content = fileSystemTree->searchFile(stdfileName);
        contentbox2->Items->Add(gcnew String(content.c_str()));
    }
    private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->BackgroundImage = originalBackgroundImage;
        buttonSearchWord->Visible = true;
        textBoxWord->Visible = true;
        googlelogo->Visible = true;
        instructionlbl->Visible = true;
        directoryLbl->Visible = false;
        listBoxResults->Visible = false;
        graphlbl->Visible = false;
        graphyesbtn->Visible = false;
        getlbl->Visible = false;
        getbtn->Visible = false;
        getbar->Visible = false;
        contentbox2->Visible = false;
        contentbox->Visible = false;
        enteredlbl->Visible = false;
    }

    private: System::Void listBoxResults_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        
        directoryLbl->Visible = false;
        listBoxResults->Visible = false;
        enteredlbl->Visible = false;
        contentbox->Visible = false;
        graphlbl->Visible = false;
        graphyesbtn->Visible = false;
        getlbl->Visible = false;
        getbtn->Visible = false;
        getbar->Visible = false;
        contentbox2->Visible = false;
        contentbox->Visible = true;
        enteredlbl->Visible = true;
        String^ filename = listBoxResults->SelectedItem->ToString();
        std::string stdfileName = marshal_as<std::string>(filename);
        string content = fileSystemTree->displayFileContent(stdfileName);
        contentbox->Text = gcnew String(content.c_str());
    }

    };
}
