#include<iostream>
#include<vector>
//#include<graphics.h>
#include<fstream>
#include<cmath>

using namespace std;

struct Color
{
   float b,g,r;
    Color();
    Color(float b,float g,float r);
    ~Color();


};

class Image
{
public:

    Image(int width,int height);
    ~Image();

    Color GetColor(int x, int y)const;
    void Read();
    void printManu();
    void Negative();
    void Grayscale();
    void Brightening();
    void Flip();
    void Sharpen();
    void Smoothing();
    void Darken();
    void Gaussian_Blur();
    void SobelEdgeDetection();
    void Angle_Calculation();
    void Histogram();
    void ShowImage(const char* path);
    void Export(const char* path)const;



private:
    int m_width;
    int m_height;
    vector<Color> m_colors;
    vector<Color> colors_modified;


};


Color :: Color()
    :b(0),g(0),r(0)
{

}

Color :: Color(float b,float g,float r)
    :b(b),g(g),r(r)
{

}

Color :: ~Color()
{

}

Image :: Image(int width,int height)
    :m_width(width),m_height(height),m_colors(vector<Color>(width*height))
{

}

Image :: ~Image()
{

}

Color Image :: GetColor(int x,int y)const
{
    return colors_modified[y*m_width+x];
}

Image readImage(0,0);


void Image::Read()
{

    string path;
    cout<<"Enter Image : ";
    cin>>path;


    ifstream f;
    f.open(path,std::ios::in | std::ios::binary);


    if(!f.is_open())
    {
        cout<<"File can't be opened!"<<endl;
        return;
    }


    const int fileHeaderSize=14;
    const int infoHeaderSize=40;

    unsigned char fileHeader[fileHeaderSize];
    f.read(reinterpret_cast<char*>(fileHeader),fileHeaderSize);

    unsigned char infoHeader[infoHeaderSize];
    f.read(reinterpret_cast<char*>(infoHeader),infoHeaderSize);

    const int fileSize=fileHeader[2]+(fileHeader[3]<<8)+(fileHeader[4]<<16)+(fileHeader[5]<<24);
    m_width=infoHeader[4]+(infoHeader[5]<<8)+(infoHeader[6]<<16)+(infoHeader[7]<<24);
    m_height=infoHeader[8]+(infoHeader[9]<<8)+(infoHeader[10]<<16)+(infoHeader[11]<<24);

    if (fileHeader[0] != 'B' && fileHeader[1] != 'M')
    {
        cout << "Invalid BMP file format!" << endl;
        return;
    }

    const int bytesPerPixel = 3;
    int paddingAmount = (4 - ((m_width * bytesPerPixel) % 4)) % 4;


    m_colors.resize(m_width*m_height);




    for(int y=0; y<m_height; ++y)
    {
        for(int x=0; x<m_width; ++x)
        {
            unsigned char color[3];

            f.read(reinterpret_cast<char*>(color),3);

            m_colors[y*m_width+x].r=static_cast<float>(color[2]);
            m_colors[y*m_width+x].g=static_cast<float>(color[1]);
            m_colors[y*m_width+x].b=static_cast<float>(color[0]);

        }
        f.ignore(paddingAmount);
    }
    f.close();

    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t!!----Image Reading Complete---!!"<<endl;

//    ShowImage((const char*)path);

}

void Image :: printManu()
{
    cout<<"\n";
    cout<<"\t\t\t";
    cout<<"!!!----------Basic Image Processing Tools----------!!!"<<endl;

    cout<<endl;
    cout<<"1->Read Image"<<endl;
    cout<<"2->Negative"<<endl;
    cout<<"3->Grayscale"<<endl;
    cout<<"4->Brightening"<<endl;
    cout<<"5->Flip Image"<<endl;
    cout<<"6->Sharpen Image"<<endl;
    cout<<"7->Smoothing Image"<<endl;
    cout<<"8->Darkening"<<endl;
    cout<<"9->Gaussian Blur"<<endl;
    cout<<"10->Sobel Edge Detection"<<endl;
    cout<<"11->Angle Detection"<<endl;
    cout<<"12->Histogram"<<endl;
    cout<<"13->Export Image"<<endl;
    cout<<"14->Exit"<<endl;


}


int main()
{

    readImage.printManu();

    bool flag;
    flag=true;


    while(flag)
    {

        int choice;
        cout<<endl;;
        cout<<"choice : ";
        cin>>choice;


        switch(choice)
        {
        case 1:
            readImage.Read();
            break;

        case 2:
            readImage.Negative();
            break;

        case 3:
            readImage.Grayscale();
            break;

        case 4:
            readImage.Brightening();
            break;

        case 5:
            readImage.Flip();
            break;

        case 6:
          readImage.Sharpen();
          break;

        case 7:
            readImage.Smoothing();
            break;

        case 8:
            readImage.Darken();
            break;

        case 9:
            readImage.Gaussian_Blur();
            break;

        case 10:
            readImage.SobelEdgeDetection();
            break;

        case 11:
            readImage.Angle_Calculation();
            break;

        case 12:
            readImage.Histogram();
            break;

        case 13:
            readImage.Export("TestImage.bmp");
            break;

        case 14:
            cout<<"\t\t\t\t...Thank You for using Image Processing Tools..."<<endl;
            flag=false;
            break;

        default :
            cout<<"Invalid Input !"<<endl;
            cout<<"Try Again."<<endl;
            flag=false;



        }

    }


    return 0;
}
