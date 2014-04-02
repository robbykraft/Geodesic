//
//
//  Geodesic Geometry Generator
//
//  Created by Robby on 3/26/14.
//  Copyright (c) 2013 Robby Kraft. All rights reserved.
//
//  Tetrahedron, Octahedron, Icosahedron
//
//  face subdivide
//  (remove duplicates)
//  spherize (geodecise)
//
//  ?: crop sphere
//
//  geometry data:
//    OBJ file format
//   points and faces (and lines, not in OBJ file)
//

// move to instruction builder:
//   lineClass_ mirror array of lines_, values are 1, 2, 3 (which group each belongs to)
//   - hidden lines and points which lie below ground level
//


#pragma mark- generate lines[] from face data


#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class Geodesic{
    
public:
    
    void icosahedron(int VFrequency);
    void octahedron(int VFrequency);
    void tetrahedron(int VFrequency);
    
    int numPoints;
    int numLines;
    int numFaces;
    
    double *points = NULL;  // each a double[3]- [0]:x [1]:y [2]:z
    int *lines = NULL;      // each an int[2]- [0]:index in points [1]:index in points
    // faces clockwise winding
    int *faces = NULL;      // each an int[3]- [0]:index in points [1]:index in points [2]:index in points
    
    double *normals = NULL;
    
private:
    
    void initShape();
    void makeOBJ();
    
    void generateNormals();
    
    bool *visiblePoints = NULL;  // size of numPoints, not size of *points array
    bool *visibleLines = NULL;   // size of numLines, not size of *lines array
    bool *visibleFaces = NULL;   // size of numFaces, not size of *faces array
    
    int *lineClass = NULL;           // size of numLines
    double *lineClassLengths = NULL; // size of
    
    int v;
    
    void loadIcosahedron();
    void loadOctahedron();
    void loadTetrahedron();
    // move a point along Y axis
    void alignIcosahedron();
    void alignTetrahedron();
    
    void divideFaces(int vFreq);
    void spherize();
    void connectTheDots();
    
    void removeDuplicatePoints();
    void geodecise(int vFreq);
    void classifyLines();
    
};



//    BOOL icosahedron; // 1 = icosa, 0 = octa

//-(id) init;
//-(id) initWithDome:(Dome*) input;
//-(id) initWithTriangle;
//-(void) geodecise:(int)v;
//-(void) geodeciseTriangle:(int)v;
//-(void) classifyLines;
//-(void) setIcosahedron;
//-(void) setOctahedron;
