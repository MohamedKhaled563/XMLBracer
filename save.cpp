#include "headerfiles.h"
#include"fstream"
int current_bit = 0;
unsigned char bit_buffer;

string toprint="";
void WriteBit (int bit,bool flag)
{
  if (bit)
    bit_buffer |= (1<<current_bit);
    current_bit++;
  if (current_bit == 8||flag==1)
  {
    char x = bit_buffer;
    toprint+=x ;
    current_bit = 0;
    bit_buffer = 0;
  }
}
void stringToBolean(string str)
{
    for(int i=0;i<str.length();i++){

        if(i==str.length()-1){
            if(str[i]=='0')WriteBit(0,1);
            else WriteBit(1,1);
        }
        else{
            if(str[i]=='0')WriteBit(0,0);
            else WriteBit(1,0);
        }
    }
}
void MainWindow::on_Save_clicked()
{
    QFile resultXML(QFileDialog::getSaveFileName(this,
                                                 tr("Save File"),
                                                 "",
                                                 tr("Text(*.txt);;XML(*.xml);;Bin(*.bin)")));

    resultXML.open(QIODevice::ReadWrite|QIODevice::Text);
    QString xmlResultString = ui->modifiedXml->toPlainText();
    string check=xmlResultString.toUtf8().constData();
    //check if its a compressed file
    if(!check[0]=='<'){
        stringToBolean(check);
        xmlResultString=QString::fromStdString(toprint);
        resultXML.write(xmlResultString.toUtf8());
        resultXML.close();
        toprint="";
        return;
    }
    resultXML.write(xmlResultString.toUtf8());
    resultXML.close();
}
