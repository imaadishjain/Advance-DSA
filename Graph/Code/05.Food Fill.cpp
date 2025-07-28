#include<bits/stdc++.h>
using namespace std;


void bfs(int i, int j,int o,int color,vector<vector<int>>&img)
    {
        int n=img.size();
        int m=img[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        
        img[i][j]=color;
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x-1>=0 && img[x-1][y]==o)
            {
                q.push({x-1,y});
                img[x-1][y]=color;
            }
            if(x+1<n && img[x+1][y]==o)
            {
                q.push({x+1,y});
                img[x+1][y]=color;
            }
            if(y-1>=0 && img[x][y-1]==o)
            {
                q.push({x,y-1});
                img[x][y-1]=color;
            }
            if(y+1<m && img[x][y+1]==o)
            {
                q.push({x,y+1});
                img[x][y+1]=color;
            }
        }
        
    }



    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if(image[sr][sc]==newColor)
        {
            return image;
        }
        vector<vector<int>>img=image;
        bfs(sr,sc,image[sr][sc],newColor,img);
        
        return img;
    }