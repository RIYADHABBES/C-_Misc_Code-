#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 73
 *  Year: 2018
 *
 *  Collecting signatures
 *
 *  Covering Segments by Points Problem
 *
 *  example :
 *
 *
 *
 *
 *      Inputs :
 *
 *
 *      Output :
 *
 *
 *
 *
*/

/* /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 * /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 * /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 *
 *              Not Working
 *
 * /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 * /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 * /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 * */
struct Segment {
    int m_lowerLimit = 0;
    int m_upperLimit = 0;

    Segment(){};
    Segment(int lowerLimit, int upperLimit) {
        if(upperLimit >= lowerLimit)
        {
            m_lowerLimit = lowerLimit;
            m_upperLimit = upperLimit;
        }
        else
        {
            m_lowerLimit = upperLimit;
            m_upperLimit = lowerLimit;
        }
    };
};

void singleSegmentsUnion(const Segment& s1, const Segment& s2, vector<Segment>& unionSegments){

    Segment farest = (s1.m_lowerLimit <= s2.m_lowerLimit) ? s1 : s2;
    Segment next = (s1.m_lowerLimit > s2.m_lowerLimit) ? s1 : s2;
    Segment theUnion;

    if(farest.m_upperLimit < next.m_lowerLimit)
        return; // Empty set
    if(farest.m_upperLimit == next.m_lowerLimit)
    {
        unionSegments.push_back(Segment(farest.m_upperLimit, next.m_lowerLimit)); // Only one point intersection ( it can contain four cases)
        return;
    }
    if(farest.m_lowerLimit == next.m_lowerLimit && farest.m_upperLimit == next.m_upperLimit)
    {
        unionSegments.push_back(Segment(farest.m_lowerLimit, farest.m_upperLimit)); // Only one point intersection or a segment
        return;
    }
    if(farest.m_lowerLimit <= next.m_lowerLimit && farest.m_upperLimit >= next.m_upperLimit)
    {
        unionSegments.push_back(Segment(next.m_lowerLimit, next.m_upperLimit)); // Only one point intersection or a segment
        return;
    }
    if(farest.m_lowerLimit <= next.m_lowerLimit && farest.m_upperLimit <= next.m_upperLimit && farest.m_upperLimit > next.m_lowerLimit)
    {
        unionSegments.push_back(Segment(farest.m_upperLimit, next.m_lowerLimit)); // Only one point intersection or a segment
        return;
    }

}

vector<Segment> allSegmentsUnion(const vector<Segment>& segments){
    vector<Segment> unionSegments = {};

    if( segments.size() > 0)
    {
        for(unsigned int i = 0; i < segments.size() - 1; ++i)
        {
            for(unsigned int j = i + 1; j < segments.size(); ++j)
                singleSegmentsUnion(segments.at(i), segments.at(j), unionSegments);
        }
    }
    return unionSegments;
}

vector<int> findPoints(const vector<Segment>& unionSegments){
    vector<int> points;
    if(unionSegments.size() > 0)
        for(unsigned int i = 0; i < unionSegments.size() - 1 ; ++i)
            for(unsigned int j = i + 1; j < unionSegments.size()  ; ++j)
            {
                int lowerPoint = unionSegments.at(i).m_lowerLimit;
                int upperPoint = unionSegments.at(i).m_upperLimit;

                if(lowerPoint >= unionSegments.at(j).m_lowerLimit && lowerPoint <= unionSegments.at(j).m_upperLimit)
                    points.push_back(lowerPoint);
                if(upperPoint >= unionSegments.at(j).m_lowerLimit && upperPoint <= unionSegments.at(j).m_upperLimit)
                    points.push_back(upperPoint);

                if((upperPoint < unionSegments.at(j).m_lowerLimit || upperPoint > unionSegments.at(j).m_upperLimit) &&
                   (upperPoint < unionSegments.at(j).m_lowerLimit || upperPoint > unionSegments.at(j).m_upperLimit)
                        )
                    points.push_back(upperPoint);
            }

    return points;
}

void printAllSegments(const vector<Segment>& segments){

    std::cout << "\nThe union segments are: \n" << std::endl;
    for(const Segment& segment : segments)
        std::cout << "    "<< segment.m_lowerLimit << " " << segment.m_upperLimit << std::endl;
    std::cout << std::endl;
}

void printAllPoints(const vector<int>& points){

    std::cout << "\nThe union segments are: \n" << std::endl;
    for(const int& point : points)
        std::cout << "    " << point << std::endl;
    std::cout << std::endl;
}

int main()
{
    vector<Segment> segments = {Segment(4, 7), Segment(1, 3), Segment(2, 5), Segment(6, 6)};
    //vector<Segment> segments = {Segment(1, 3), Segment(2, 5), Segment(3, 6)};

    printAllSegments(allSegmentsUnion(segments));

    printAllPoints(findPoints(allSegmentsUnion(segments)));
}
