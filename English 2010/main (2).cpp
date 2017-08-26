#include <iostream>
#include <fstream>

using namespace std;

const int ROWS=1024;
const int COLS=1024;
const int MAXITERS=1000;
const float c1r=-1.49;
const float c1i=.01;
const float c2r=-1.47;  //  These values create a cool picture.
const float c2i=-.01;


struct ComplexN{
    float realN;
    float imagN;
};

struct Color{
    int red;
    int green;
    int blue;
};

ComplexN addComplexNumbers(ComplexN num1, ComplexN num2)
{
    ComplexN sum;
    sum.realN = num1.realN + num2.realN;
    sum.imagN = num1.imagN + num2.imagN;
    return sum;

}

ComplexN multiplyComplexNumbers(ComplexN num1, ComplexN num2)
{
    ComplexN product;
    product.realN = num1.realN*num2.realN - num1.imagN*num2.imagN;
    product.imagN = num1.realN*num2.imagN + num1.imagN*num2.realN;

    return product;
}

//THIS RETURNS THE 'DISTANCE' BETWEEN EACH COLUMN
float getColumnDistance(int cLoop, ComplexN num1, ComplexN num2)
{
    float travelDistance;
    float distanceColumn;
    travelDistance=(num2.realN-num1.realN)/COLS;
    distanceColumn = num1.realN +(travelDistance*cLoop);
    return distanceColumn;

}

// THIS RETURNS THE DISTANCE BETWEEN EACH ROW
float getRowDistance(int rLoop, ComplexN num1, ComplexN num2)
{
    float travelDistance;
    float distanceRow;
    travelDistance=(num2.imagN-num1.imagN)/ROWS;
    distanceRow = num1.imagN +(travelDistance*rLoop);
    return distanceRow;

}

// THIS TAKE THE TWO PREVIOUS FUNCTIONS AND GETS THE X,Y COORDINATE FOR THE PARTICULAR PIXEL
ComplexN getExactPoint(int rLoop, int cLoop, ComplexN num1, ComplexN num2)
{
    ComplexN exactPoint;
    exactPoint.realN = getColumnDistance(cLoop, num1, num2);
    exactPoint.imagN = getRowDistance(rLoop, num1, num2);
    return exactPoint;

}

// THIS TAKES THE EXACT POINT RETURNS AN INT BASED OFF THAT POINT
// THAT WILL BE USED LATER TO DETERMINE THE COLOR OF THE PIXEL WE
// ARE WORKING ON
int getMbrotData(ComplexN num1)
{
    int i = 0;
    ComplexN myNum;
    myNum = num1;

    while(myNum.realN*myNum.realN+myNum.imagN*myNum.imagN<4&&i<MAXITERS)
    {
        myNum=multiplyComplexNumbers(myNum,myNum);
        myNum=addComplexNumbers(myNum,num1);
        i++;
    }


    return i;

}

 // THIS TAKES THE DATA FOUND USING THE MATH FROM THE PIXEL
 // IF COORDINATES SQUARED OF THE PIXEL IS LESS THAN THE AREA OF THE SIZE OF
 // OUR PICTURE THEN IT WILL RETURN A COLOR, IF ITS GREATER THEN WILL RETURN BACK;
Color getPixelColor(unsigned int data)
{
    Color toReturn;
    data%=MAXITERS/10;
    toReturn.red = data*30;
    toReturn.green = data*10;
    toReturn.blue = data*40;
    return toReturn;
}

void printColor(Color c, ofstream &fileOut)
{
    fileOut << c.red <<" ";
    fileOut << c.green <<" ";
    fileOut << c.blue <<" ";
    fileOut << endl;
}
int main(){
    ofstream fileOut;
    ifstream fileIn;
    fileIn.open("mandelinput.txt");
    fileOut.open("mandeloutput.ppm");
    ComplexN corner1, corner2;
    //fileIn >> corner1.realN;
    //fileIn >> corner1.imagN;
    //fileIn >> corner2.realN;
    //corner2.imagN = corner1.imagN +(corner1.realN - corner2.realN);
    corner1.realN = c1r;
    corner1.imagN = c1i;
    corner2.realN = c2r;
    corner2.imagN = c2i;
    Color pixelColor;
    ComplexN pixel;
    int data;
    if(fileIn.is_open())
    {
        cout << "Please wait for the program to finish running" << endl;
    } else
    {
        cout << "ERROR READING FILE: File name shoule be 'mandelinput.txt'" << endl;
    }
    fileOut<<"P3 ";
    fileOut<<COLS<< " ";
    fileOut<<ROWS<< " ";
    fileOut<<"255 ";
    fileOut<<endl;

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            pixel=getExactPoint(i,j,corner1,corner2);
            data = getMbrotData(pixel);
            pixelColor = getPixelColor(data);
            printColor(pixelColor,fileOut);

        }
    }

    fileIn.close();
    fileOut.close();
    return 0;
}

