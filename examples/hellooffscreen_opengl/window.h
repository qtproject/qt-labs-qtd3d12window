/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the QtD3D12Window module
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QOpenGLWindow>
#include <QMatrix4x4>

QT_BEGIN_NAMESPACE
class QOpenGLFramebufferObject;
class QOpenGLShaderProgram;
class QOpenGLBuffer;
class QOpenGLVertexArrayObject;
QT_END_NAMESPACE

class Window : public QOpenGLWindow
{
public:
    Window();
    ~Window();

    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;

public slots:
    void readbackAndSave();

private:
    void initializeOffscreen();
    void initializeOnscreen();
    void setupOffscreenVertexAttribs();
    void paintOffscreen();
    void setupOnscreenVertexAttribs();
    void paintOnscreen();

    struct OffscreenData {
        OffscreenData() : rotationAngle(0), fbo(Q_NULLPTR), prog(Q_NULLPTR), vbo(Q_NULLPTR), vao(Q_NULLPTR) { }
        QMatrix4x4 projection;
        float rotationAngle;
        QOpenGLFramebufferObject *fbo;
        QOpenGLShaderProgram *prog;
        QOpenGLBuffer *vbo;
        QOpenGLVertexArrayObject *vao;
        int modelviewLoc;
        int projectionLoc;
    } offscreen;

    struct OnscreenData {
        OnscreenData() : rotationAngle(0), prog(Q_NULLPTR), vbo(Q_NULLPTR), vao(Q_NULLPTR) { }
        QMatrix4x4 projection;
        float rotationAngle;
        QOpenGLShaderProgram *prog;
        QOpenGLBuffer *vbo;
        QOpenGLVertexArrayObject *vao;
        int modelviewLoc;
        int projectionLoc;
    } onscreen;
};