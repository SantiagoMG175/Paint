#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    m_imagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    m_imagen->fill(Qt::white);
    m_painter = new QPainter(m_imagen);
    m_opcion = 1;
}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    QPainter painter (this);
    painter.drawImage(0,0,*m_imagen);
    event->accept();

}

void Principal::mousePressEvent(QMouseEvent *event)
{
    if(m_opcion == 1){
            m_ptInicial = event->pos();
        }else if(m_opcion == 2){
            if(m_toogle){
                m_ptInicial = event->pos();
            }else{
                m_ptFinal = event->pos();
                QPen pincel;
                m_painter->setPen(pincel);
                m_painter->drawLine(m_ptInicial, m_ptFinal);
                update();
            }
        }else if(m_opcion == 3){
            if(m_toogle){
                m_ptInicial = event->pos();
            }else{
                m_ptFinal = event->pos();
                int ancho = m_ptFinal.x() - m_ptInicial.x();
                int alto = m_ptFinal.y() - m_ptInicial.y();

                QPen pincel;
                m_painter->setPen(pincel);
                m_painter->drawRect(m_ptInicial.x(), m_ptInicial.y(), ancho, alto);
                update();
            }
        }else if(m_opcion == 4){
            if(m_toogle){
                m_ptInicial = event->pos();
            }else{
                m_ptFinal = event->pos();
                int m_ancho = m_ptFinal.x() - m_ptInicial.x();
                int m_alto = m_ptFinal.y() - m_ptInicial.y();
                QPen pincel;
                m_painter->setPen(pincel);
                QRectF rectangle(m_ptInicial.x(),m_ptInicial.y(),m_ancho,m_alto);
                m_painter->drawEllipse(rectangle);
                update();


            }
        }
        m_toogle = !m_toogle;

}

void Principal::mouseMoveEvent(QMouseEvent *event)
{
   if(m_opcion == 1){
    m_ptFinal = event->pos();
    QPen pincel ;
    pincel.setColor(Qt::red);
    m_painter->setPen(pincel);
    m_painter->drawLine(m_ptInicial, m_ptFinal);

    }

    update();

    m_ptInicial  = m_ptFinal;
}


void Principal::on_actionLibre_triggered()
{
    m_opcion = 1;
}

void Principal::on_actionLineas_triggered()
{
    m_opcion = 2;
}

void Principal::on_actionRectangulos_triggered()
{
    m_opcion = 3;
}

void Principal::on_actionCincurferencias_triggered()
{
    m_opcion = 4;
}
