#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle("Распределятор фотографий");
    setFixedSize(550, 550);

    QPixmap image(":/img/img1.png");
    image = image.scaled(190, 60, Qt::IgnoreAspectRatio);
    ui->TitlePic->setPixmap(image);

            ui->Pictures->setHidden(1);
            ui->Folders->setHidden(1);
            ui->Move_Pics->setHidden(1);
            ui->Random->setHidden(1);

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::on_Input_Folder_clicked() {

    QString ip = QFileDialog::getExistingDirectory(this, "Папка с фотографиями",
                                                    QDir::current().path());

    ui->InputPath->setText(ip);

    auto fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::rootPath());
    fileSystemModel->setReadOnly(false);

        ui->Pictures->setModel(fileSystemModel);
        ui->Pictures->setRootIndex(fileSystemModel->index(ip));

    if (ui->InputPath->text() != 0 && ui->OutputPath->text() != 0) {

        ui->Move_Pics->setHidden(0);
        ui->Random->setHidden(0);
        ui->Pictures->setHidden(0);

    } else if (ui->InputPath->text() != 0) {

        ui->Pictures->setHidden(0);

    }

}

void MainWindow::on_Output_Folder_clicked() {

    QString op = QFileDialog::getExistingDirectory(this, "Папка с каталогами",
                                                    QDir::current().path());

    ui->OutputPath->setText(op);

    auto fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::rootPath());
    fileSystemModel->setReadOnly(false);

        ui->Folders->setModel(fileSystemModel);
        ui->Folders->setRootIndex(fileSystemModel->index(op));

    if (ui->InputPath->text() != 0 && ui->OutputPath->text() != 0) {

        ui->Move_Pics->setHidden(0);
        ui->Random->setHidden(0);
        ui->Folders->setHidden(0);

    } else if (ui->OutputPath->text() != 0) {

        ui->Folders->setHidden(0);

    }

}

void MainWindow::on_Move_Pics_clicked() {

    QDir inputDir(ui->InputPath->text());
    QDir outputDir(ui->OutputPath->text());
    QStringList iDir = inputDir.entryList(QDir::Files, QDir::Name);
    QStringList oDir = outputDir.entryList(QDir::Dirs, QDir::Name);
    int j = oDir.size();
    int i = 2;
    QDir f(inputDir);
    bool renamed;
    QRandomGenerator rg;
    rg.seed(time(NULL));
    int v;

        foreach(QString file, iDir) {

            v = rg.generate() % 10000;

            if (j == 2) {

                QFileInfo check(ui->OutputPath->text() + "/" + file);
                if(!check.exists()) {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + file);

                } else {

                    renamed = f.rename(file, ui->OutputPath->text() + "/"
                                       + QString::number(v / 100) + "__"  + file);

                }

            } else if (i != j) {

                QFileInfo check(ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);
                if(!check.exists()) {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);

                } else {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/"
                                       + QString::number(v / 100) + "__"  + file);

                }

                i++;

            } else {

                i = 2;
                QFileInfo check(ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);
                if(!check.exists()) {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);

                } else {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/"
                                       + QString::number(v) + "__"  + file);

                }

                i++;

            }

        }

        QMessageBox::information(this, "Информация", "Фотографии распределены!");

}

void MainWindow::on_Random_clicked() {

    QDir inputDir(ui->InputPath->text());
    QDir outputDir(ui->OutputPath->text());
    QStringList iDir = inputDir.entryList(QDir::Files, QDir::Name);
    QStringList oDir = outputDir.entryList(QDir::Dirs, QDir::Name);
    int j = oDir.size();
    int i = 2;
    QDir f(inputDir);
    bool renamed;
    QRandomGenerator rg;
    rg.seed(time(NULL));
    int v;

    std::shuffle(iDir.begin(), iDir.end(), rg);
        foreach(QString file, iDir) {

            v = rg.generate() % 10000;

            if (j == 2) {

                QFileInfo check(ui->OutputPath->text() + "/" + file);
                if(!check.exists()) {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + file);

                } else {

                    renamed = f.rename(file, ui->OutputPath->text() + "/"
                                       + QString::number(v / 100) + "__"  + file);

                }

            } else if (i != j) {

                QFileInfo check(ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);
                if(!check.exists()) {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);

                } else {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/"
                                       + QString::number(v / 100) + "__"  + file);

                }

                i++;

            } else {

                i = 2;
                QFileInfo check(ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);
                if(!check.exists()) {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/" + file);

                } else {

                    renamed = f.rename(file, ui->OutputPath->text() + "/" + oDir.at(i) + "/"
                                       + QString::number(v) + "__"  + file);

                }

                i++;

            }

        }

        QMessageBox::information(this, "Информация", "Фотографии распределены!");

}
