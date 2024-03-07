#include "./flipAndInvertImage.h"
#include <vector>

std::vector<int> int_atov (int arr[], int len) {
    std::vector<int> vec(arr, arr + len);
    return vec;
}

std::vector< std::vector<int> > FlipAndInvertImageSolution::flipAndInvertImage(std::vector< std::vector<int> > &image)
{
    int n = image.size();
    for (int i = 0; i < n; ++i)
    {
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (image[i][left] == image[i][right])
            {
                image[i][left] ^= 1;
                image[i][right] ^= 1;
            }
            left++;
            right--;
        }
        if (left == right)
        {
            image[i][left] ^= 1;
        }
    }
    return image;
}

// int main()
// {
//     int test[3][3] = {
//         {1, 1, 0},
//         {1, 0, 1},
//         {0, 0, 0},
//     };
//     int test_len = sizeof(test)/sizeof(test[0]);
//     cout<<"test_len: "<<test_len<<endl;
//     vector< vector<int> > vv_int;
//     for (int i = 0; i < test_len; i++)
//     {
//         int a[test_len];
//         for (int j = 0; j < test_len; j++)
//         {
//             a[j] = test[i][j];
//         }
//         vector<int> v_int = int_atov(a, test_len);
//         // cout<<"v_int: "<<v_int.size()<<endl;
//         vv_int.insert(vv_int.end(), v_int);
//     }
//     vv_int = flipAndInvertImage(vv_int);
//     // cout<<"vv_int: "<<vv_int.size()<<endl;
//     for (int i = 0; i < vv_int.size(); i++)
//     {
//         for (int j = 0; j < vv_int[i].size(); j++)
//         {
//             cout<<"vv_int[i].size(): "<<vv_int[i].size()<<endl;
//             cout<<"i: "<<i<<" j: "<<j<<" v: "<<vv_int[i][j]<<"\n"<<endl;
//         }
        
//     }
    
// }