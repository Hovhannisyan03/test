#ifndef PLUS_BUTTON_H
#define PLUS_BUTTON_H

#include <QWidget>
#include <QVBoxLayout>
#include <QToolButton>
#include <QGridLayout>
#include <QListWidget>

class plus_button : public QWidget
{
    Q_OBJECT
public:
    plus_button(QWidget *parent);
    ~plus_button();
private slots:
    void window_show_hide();
private:
    void create_plus_button();
    QWidget *central_widget;
    QVBoxLayout *main_layout;
    QToolButton *create_document_button;
    QGridLayout *mid_side_bar_layout;
    QListWidget *template_list;
    bool check_and_set_logo;
};

#endif // PLUS_BUTTON_H
