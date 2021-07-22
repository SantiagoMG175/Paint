#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:

    void paintEvent(QPaintEvent *event ) override;
    void mousePressEvent(QMouseEvent *event )override;
    void mouseMoveEvent(QMouseEvent *event) override;


private slots:
    void on_actionLibre_triggered();
    void on_actionLineas_triggered();
    void on_actionRectangulos_triggered();
    void on_actionCincurferencias_triggered();

private:
    Ui::Principal *ui;
    QImage *m_imagen;
    QPainter *m_painter;
    QPoint m_ptInicial;
    QPoint m_ptFinal;
    int m_opcion;
    bool m_toogle = true;
};
#endif // PRINCIPAL_H
