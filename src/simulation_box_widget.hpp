#pragma once

#include <memory>

#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QPainter>

#include "particle.hpp"
#include "simulation_box.hpp"

extern int OFFSET_X;
extern int OFFSET_Y;
extern float PAINTING_RADIUS;
extern float UPDATE_THIS;
extern float UPDATE_SYSTEM;


class SimulationBoxWidget : public QWidget
{
    Q_OBJECT
public:
    SimulationBoxWidget(std::shared_ptr<SimulationBox> simulationBox_ptr);
    std::shared_ptr<SimulationBox> getSimulationBox_ptr();
public slots:
    void updateParticlesSystem();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QTimer* thisTimer_ptr;
    QTimer* systemTimer_ptr;
    std::shared_ptr<SimulationBox> simulationBox_ptr;
};
