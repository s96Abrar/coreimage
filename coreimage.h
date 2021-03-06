/*
CoreImage is image viewer

CoreImage is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef COREIMAGE_H
#define COREIMAGE_H

#include <QWidget>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QScrollBar>
#include <QListWidgetItem>
#include <QLabel>
#include <QSpacerItem>

namespace Ui {
class coreimage;
}

class coreimage : public QWidget
{
    Q_OBJECT

public:
    explicit coreimage(QWidget *parent = nullptr);
    ~coreimage();

    void sendFiles(const QStringList &paths);
    bool loadFile(const QString &);
    QString workFilePath;

private slots:
    void on_cOpen_clicked();
    void on_cZoomIn_clicked();
    void on_cZoomOut_clicked();
    void on_cNormalSize_clicked();
    void on_cRotateLeft_clicked();
    void on_cRotateRight_clicked();
    void on_cSave_clicked();
    void on_cSaveAs_clicked();
    void on_cTools_clicked(bool checked);
    void on_bookMarkIt_clicked();
    void on_cPrevious_clicked();
    void on_cNext_clicked();
    void on_cProperties_clicked(bool checked);
    void on_openThumbview_clicked();
    void on_thumnailView_itemClicked(QListWidgetItem *item);
    void on_cTrashIt_clicked();
    void on_containingFolder_clicked();
    void on_openInEditor_clicked();
    void on_slideShow_clicked(bool checked);

protected:
    virtual void wheelEvent(QWheelEvent *event);
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);  
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::coreimage *ui;
    QSpacerItem *hSpacer;   
    QTimer *slideShowTimer;
    QStringList images;

    // A temporary image
    QImage image;
    double scaleFactor;
    QLabel *cImageLabel;
    bool   mousePressed;
    bool   sildeShow;
    QPoint mousePos;
    QPoint wndPos;

    QStringList getImages(const QString &path);
    bool saveFile(const QString &fileName);
    void setImage(const QImage &newImage);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    void shotcuts();

};

#endif // COREIMAGE_H
