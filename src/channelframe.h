#ifndef ASTCHANFORM_H
#define ASTCHANFORM_H

#include <QWidget>

namespace Ui {
    class AstChanForm;
}

class AstChanForm : public QWidget {
    Q_OBJECT
public:
    AstChanForm(QWidget *parent = 0);
    ~AstChanForm();

    void setLabel(int label, QString value);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AstChanForm *ui;
};

#endif // ASTCHANFORM_H
