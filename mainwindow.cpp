/*    This file is part of MedRNG.

    MedRNG is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MedRNG is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MedRNG.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QStringListModel>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(MedRNG);

}





MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileButton_clicked()
{
    QVector<QString> myLines;
    QString inFileName = QFileDialog::getOpenFileName(

                this,
                tr("Open File"),
                "~/",
                "All files (*.*);;Text File (*.txt)"
                 );

    QFile file (inFileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


        QTextStream in(&file);
        QString line = in.readLine();
        while (!line.isNull()) {
            myLines.push_back(line);
            line = in.readLine();
        }

    //std::vector<QString> stdvector = myLines.toStdVector();

    //std::random_shuffle ( stdvector.begin(), stdvector.end() );

    std::random_shuffle(myLines.begin(), myLines.end());

        int n = ui->randomPicks->text().toInt();

       std::cout << n;

       QString outFileName = QFileDialog::getSaveFileName(

                   this,
                   tr("Save File"),
                   "~/",
                   "All files (*.*);;Text File (*.txt)"
                    );
       QFile outFile(outFileName);
           outFile.open(QIODevice::WriteOnly | QIODevice::Text);
           QTextStream out(&outFile);
           if (n<myLines.size())
           for (int i = 0; i<n; ++i)
           {

               out << myLines[i];
               out << "\n";
}


           outFile.close();


    //if (n<stdvector.size()) for (int i=0; i<n; i++) qDebug(stdvector[i]);
   // ui->listView->setModel(new QStringListModel(QList<QString>::fromStdVector(stdvector)));


}



