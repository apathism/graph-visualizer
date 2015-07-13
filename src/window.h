#ifndef MAPVISUALIZER_WINDOW_H
#define MAPVISUALIZER_WINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QWebEngineView* web;

    bool loadMapFromFile(const QString &file = "map.html") const;
};

#endif
