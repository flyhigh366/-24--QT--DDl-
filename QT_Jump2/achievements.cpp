#include "achievements.h"
#include "ui_achievements.h"
#include <QSettings>
#include <QVBoxLayout>
#include <QFrame>
#include <QSoundEffect>
#include <QUrl>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QScrollArea>

achievements::achievements(QWidget *parent)
    : QDialog(parent), ui(new Ui::achievements)
{
    ui->setupUi(this);
    // ===== 读取成就状态 =====
    bool acFullStack = gameview::hasAchievement("ACH_FULLSTACK");
    bool acAC        = gameview::hasAchievement("ACH_AC");
    bool acRMRF      = gameview::hasAchievement("ACH_RMRF");
    bool acTLE       = gameview::hasAchievement("ACH_TLE");
    bool acSO        = gameview::hasAchievement("ACH_STACKOVERFLOW");
    bool acSegFault  = gameview::hasAchievement("ACH_SEGFAULT");

    // ===== 根据状态让按钮发光 =====
    applyGlow(ui->btnFullStack, acFullStack);
    applyGlow(ui->btnAC, acAC);
    applyGlow(ui->btnRMRF, acRMRF);
    applyGlow(ui->btnTLE, acTLE);
    applyGlow(ui->btnSO, acSO);
    applyGlow(ui->btnSegFault, acSegFault);


}

achievements::~achievements()
{
    delete ui;
}
void achievements::on_btn_back_clicked()
{
    this->reject();
}


void achievements::on_btn_start_clicked()
{
    this->accept();
}

// ===== 发光函数 =====
void achievements::applyGlow(QPushButton *btn, bool achieved)
{
    if (!btn) return;
    if (achieved) {
        btn->setStyleSheet(
            "QPushButton {"
            "  background-color: #89FF96;"
            "  border: 1px solid #39E04E;"
            "  border-radius: 18px;"
            "  color: #003300;"
            "}"
            );

        QGraphicsDropShadowEffect *glow = new QGraphicsDropShadowEffect(this);
        glow->setColor(QColor("#32E648"));
        glow->setBlurRadius(20);
        glow->setOffset(0, 0);
        btn->setGraphicsEffect(glow);
    } else {
        btn->setStyleSheet(
            "QPushButton {"
            "  background: white;"
            "  border: 1px solid #ddd;"
            "  border-radius: 10px;"
            "}"
            );
        btn->setGraphicsEffect(nullptr);
    }
}