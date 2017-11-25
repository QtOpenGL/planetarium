#ifndef MODEL_H
#define MODEL_H

#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QTextStream>
#include <QFile>

#include <fstream>
#include <limits>
#include <iostream>
#include <memory>

#include "light.h"
#include "trackball.h"
#include "material.h"

class Model : public QOpenGLExtraFunctions
{
public:
    Model(QOpenGLWidget *_glWidget);
    ~Model();

    std::unique_ptr<QVector4D []> vertices;
    std::unique_ptr<QVector3D []> normals;
    std::unique_ptr<unsigned int[]> indices;
    std::unique_ptr<QVector2D []> texCoords;
    std::unique_ptr<QVector4D []> tangents;

    QOpenGLWidget *glWidget;

    unsigned int numVertices;
    unsigned int numFaces;

    void createNormals();
    void createTexCoords();
    void createTangents();

    GLuint vao = 0;

    GLuint vboVertices = 0;
    GLuint vboIndices = 0;
    GLuint vboNormals = 0;
    GLuint vboTexCoords = 0;
    GLuint vboTangents = 0;
    GLuint textureID = 0;
    GLuint textureLayerID = 0;
    GLuint textureCubeMapID = 0;

    void createVBOs();
    void createShaders();

    void destroyVBOs();
    void destroyShaders();

    void drawModel();

    QMatrix4x4 modelMatrix;
    QVector3D midPoint;
    double invDiag;
    double zoom = 0;

    Material material;

    int shaderIndex;
    int numShaders;

    std::vector<GLuint> shaderProgram;

    TrackBall trackBall;

    void readOFFFile(const QString &fileName);
    void loadTexture(const QImage &image);
};

#endif // MODEL_H
