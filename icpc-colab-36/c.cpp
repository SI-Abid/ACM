#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// points on a sphere
class point
{
// private:
public:
    double x;
    double y;
    double PI = acos(-1);
    point(){}
    point(double lat, double lon)
    {
        x = lat;
        y = lon;
    }
    friend ostream& operator<<(ostream& os,point p)
    {
        os<<"("<<p.x<<","<<p.y<<")";
        return os;
    }
    double distance(point p)
    {
        // in meters
        return sqrt(pow(p.x-x,2)+pow(p.y-y,2));
    }
};

double polyArea(vector<point> p)
{
    double area=0;
    for(int i=0;i<p.size();i++)
    {
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }
    return abs(area)/2.0;
}

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

vector<point> convexHull(vector<point> &points)
{
    int n = points.size();
    if (n < 3) return points;
 
    vector<point> hull;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
 
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
 
        p = q;
 
    } while (p != l);
 
    return hull;
}
int main()
{
    int n;
    cin>>n;
    vector<point> v(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>v[i].x>>v[i].y;
    }
    sort(v.begin(),v.end(),[](point a,point b){
        return a.x<b.x;
    });
    for(auto x:v)
    {
        cout<<x<<endl;
    }
    cout<<polyArea(v);
    puts("==========");
    for(auto x:convexHull(v))
    {
        cout<<x<<endl;
    }
    cout<< polyArea(convexHull(v));
    double area
    // cout<<center<<endl;
    return 0;
}