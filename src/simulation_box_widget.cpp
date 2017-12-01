#include "simulation_box_widget.hpp"


SimulationBoxWidget::SimulationBoxWidget(std::shared_ptr<SimulationBox> simulationBox_ptr) {
    this->simulationBox_ptr = simulationBox_ptr;
    thisTimer_ptr = new QTimer(this);
    thisTimer_ptr->setInterval(40);
    QObject::connect(thisTimer_ptr, SIGNAL(timeout()), this, SLOT(update()));
    thisTimer_ptr->start();
    systemTimer_ptr = new QTimer(this);
    systemTimer_ptr->setInterval(1);
    QObject::connect(systemTimer_ptr, SIGNAL(timeout()), this, SLOT(updateParticlesSystem()));
    systemTimer_ptr->start();
}


void SimulationBoxWidget::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    std::vector<std::shared_ptr<Particle> > particle_ptrs =
        simulationBox_ptr->getParticlesSystem_ptr()->getParticle_ptrs();
    std::vector<std::shared_ptr<Bond> > bond_ptrs =
        simulationBox_ptr->getParticlesSystem_ptr()->getBond_ptrs();
    for (auto par : particle_ptrs)
        p.drawEllipse(par->x() + OFFSET_X - PAINTING_RADIUS / 2,
                      par->y() + OFFSET_Y - PAINTING_RADIUS / 2,
                      PAINTING_RADIUS, PAINTING_RADIUS);
    for (auto bon : bond_ptrs)
        p.drawLine(bon->getParticle1_ptr()->x() + OFFSET_X,
                   bon->getParticle1_ptr()->y() + OFFSET_Y,
                   bon->getParticle2_ptr()->x() + OFFSET_X,
                   bon->getParticle2_ptr()->y() + OFFSET_Y);
}

void SimulationBoxWidget::updateParticlesSystem() {
    simulationBox_ptr->getParticlesSystem_ptr()->update();
}

std::shared_ptr<SimulationBox> SimulationBoxWidget::getSimulationBox_ptr() {
    return simulationBox_ptr;
}

