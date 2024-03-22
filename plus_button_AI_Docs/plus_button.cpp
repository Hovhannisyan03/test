#include "plus_button.h"
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QTimer>
#include <QString>


plus_button::plus_button(QWidget *parent) : QWidget(parent)
{
    central_widget = nullptr;
    main_layout = nullptr;
    create_document_button = nullptr;
    mid_side_bar_layout = nullptr;
    template_list = nullptr;
    check_and_set_logo = 0;
    create_plus_button();
}


void plus_button::create_plus_button()
{

    setStyleSheet("background-color: white");
    setWindowTitle("Google Docs Mid-Side Bar");
    setGeometry(200, 200, 600, 400);
    central_widget = new QWidget(this);

    main_layout = new QVBoxLayout(central_widget);

    main_layout->setContentsMargins(0,40,0,0);
    QLabel *new_document_line = new QLabel("Start a new Document", this);
    new_document_line->setStyleSheet("font-weight: bold; font-size: 10px; margin-left: 10px");

    mid_side_bar_layout = new QGridLayout;
    main_layout->addLayout(mid_side_bar_layout);
    mid_side_bar_layout->addWidget(new_document_line,0,5,1,1);

    QToolButton *template_gallery_button = new QToolButton;
    template_gallery_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    template_gallery_button->setText("Template Gallery");
    template_gallery_button->setIcon(QIcon("D:/ai docs/plus_button_AI_Docs/template_gallery.png"));
    template_gallery_button->setStyleSheet("background-color: white; border: solid 2px white;");

    mid_side_bar_layout->addWidget(template_gallery_button, 0, 45, 1, 1);

    QToolButton *hide_templates_button = new QToolButton;
    hide_templates_button->setIcon(QIcon("D:/ai docs/plus_button_AI_Docs/dots.png"));
    hide_templates_button->setStyleSheet("background-color: white; border: solid 2px white");
    mid_side_bar_layout->addWidget(hide_templates_button,0,48,1,1);

    template_list = new QListWidget(this);
    template_list->setViewMode(QListWidget::IconMode);
    template_list->setIconSize(QSize(80, 80));
    template_list->setStyleSheet("background-color: gray; padding: 25px");
    mid_side_bar_layout->addWidget(template_list, 1, 0, 1, 80);

    QListWidgetItem *template_item1 = new QListWidgetItem(QIcon("D:/ai docs/plus_button_AI_Docs/plus_template.png"), "Blank\nDocument", template_list);
    template_item1->setFont(QFont("Arial", 8, QFont::Bold));
    template_item1->setSizeHint(QSize(78, 120));

    QListWidgetItem *template_item2 = new QListWidgetItem(QIcon("D:/ai docs/plus_button_AI_Docs/letter_template.png"), "Letter\nSpearmint", template_list);
    template_item2->setFont(QFont("Arial", 8, QFont::Bold));
    template_item2->setSizeHint(QSize(78, 120));

    QListWidgetItem *template_item3 = new QListWidgetItem(QIcon("D:/ai docs/plus_button_AI_Docs/resume_template.png"), "Resume\nSerif", template_list);
    template_item3->setFont(QFont("Arial", 8, QFont::Bold));
    template_item3->setSizeHint(QSize(78, 120));

    QListWidgetItem *template_item4 = new QListWidgetItem(QIcon("D:/ai docs/plus_button_AI_Docs/resume2_template.png"), "Resume\nCoral", template_list);
    template_item4->setFont(QFont("Arial", 8, QFont::Bold));
    template_item4->setSizeHint(QSize(78, 120));

    QListWidgetItem *template_item5 = new QListWidgetItem(QIcon("D:/ai docs/plus_button_AI_Docs/project_template.png"), "Project\nTropic", template_list);
    template_item5->setFont(QFont("Arial", 8, QFont::Bold));
    template_item5->setSizeHint(QSize(78, 120));

    QListWidgetItem *template_item6 = new QListWidgetItem(QIcon("D:/ai docs/plus_button_AI_Docs/brochure_template.png"), "Brochure\nGeometric", template_list);
    template_item6->setFont(QFont("Arial", 8, QFont::Bold));
    template_item6->setSizeHint(QSize(78, 120));
    QListWidgetItem *template_item7 = new QListWidgetItem(QIcon("D:/ai docs/plus_button_AI_Docs/report_template.png"), "Report\nLuxe", template_list);
    template_item7->setFont(QFont("Arial", 8, QFont::Bold));
    template_item7->setSizeHint(QSize(78, 120));

    create_document_button = new QToolButton;
    create_document_button->setIcon(QIcon("D:/ai docs/plus_button_AI_Docs/plusIcon.png"));
    create_document_button->setStyleSheet("width: 50px; height: 50px; border-radius: 2px; margin-top: 80px; margin-left:550px");
    main_layout->addWidget(create_document_button);
    main_layout->setAlignment(create_document_button, Qt::AlignBottom);
    QTimer::singleShot(0,this, &plus_button::window_show_hide);

    connect(create_document_button, &QToolButton::clicked,this, &plus_button::window_show_hide);
}

void plus_button::window_show_hide()
{
    if(!check_and_set_logo)
    {
        check_and_set_logo = 1;
        create_document_button->setIcon(QIcon("D:/ai docs/plus_button_AI_Docs/plusIcon.png"));
    }
    else
    {
        check_and_set_logo = 0;
        create_document_button->setIcon(QIcon("D:/ai docs/plus_button_AI_Docs/closeIcon.png"));
    }

    for (int i = 0; i < mid_side_bar_layout->count(); ++i) {
        mid_side_bar_layout->itemAt(i)->widget()->setVisible(!mid_side_bar_layout->itemAt(i)->widget()->isVisible());
    }
}

plus_button::~plus_button()
{
    delete central_widget;
    delete main_layout;
    delete create_document_button;
    delete mid_side_bar_layout;
    delete template_list;
}
