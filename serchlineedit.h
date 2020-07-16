#ifndef SERCHLINEEDIT_H
#define SERCHLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>

class SerchLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    SerchLineEdit(QWidget *parent=nullptr);

    // QWidget interface
protected:
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);

private:
    QString m_initContent;
};

#endif // SERCHLINEEDIT_H
