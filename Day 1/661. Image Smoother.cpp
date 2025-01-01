class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                int sum = 0;
                int count = 0;
                for (int x=i-1;x<=i+1;x++) {
                    for (int y=j-1;y<=j+1;y++) {
                        if (x>=0 && x<m && y>=0 && y<n) {
                            sum+=(img[x][y] & 255);
                            count+=1;
                        }
                    }
                }
                img[i][j] = img[i][j]|(sum/count)<<8;
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                img[i][j] = img[i][j]>>8;
            }
        }
        return img;
    }
};
