#include<iostream>
using namespace std;

class image{
private:
    float height, width;
    int *dataPointer;

public:
    image(float hight, float width, int *imagePter){
        this->height = hight;
        this->width = width;
        // Corrected allocation of memory using square brackets []
        dataPointer = new int[(int)(height * width)];

        // Copy provided image data
        for (size_t i = 0; i < height * width; i++) {
            dataPointer[i] = imagePter[i];
        }
    }

    image(const image &otherImage) : width(otherImage.width), height(otherImage.height) {
        dataPointer = new int[(int)(width * height)];

        // Copy data from the original image
        for (int i = 0; i < width * height; ++i) {
            dataPointer[i] = otherImage.dataPointer[i];
        }
    }

    ~image(){
        delete[] dataPointer;
    }

    void display(){
        cout << "Displaying Image" << endl;
        for(int i=0; i < height*width; i++){
            cout << dataPointer[i] << " ";
        }
        cout << endl;
    }
     void updateData() {
        for (int i = 0; i < width * height; ++i) {
            if (dataPointer[i] <= 0) {
                // Assign a random value between 1 and 255
                dataPointer[i] = rand() % 255 + 1;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int sampleData[6] = {1, 2, 3, -1, -2, -3};

    // Create original Image object
    image original(2, 3, sampleData);

    // Create a copy of the original Image object
    image copy(original);

    // Display original and copied images
    cout<<endl<<"befor update:"<<endl;

    cout<<"Original Image: "<<endl;
    original.display();
    cout<<"Copied Image: "<<endl;
    copy.display();
   
    //update the value in the orignal image
    original.updateData();
    copy.updateData();

    cout<<endl<<"after update:"<<endl;
    cout<<"Original Image: "<<endl;
    original.display();
    cout<<"Copied Image: "<<endl;
    copy.display();
   
    return 0;
}
