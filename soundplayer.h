#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>

class SoundPlayer : public QObject
{
    Q_OBJECT
public:
    SoundPlayer();
public slots:
    bool playSoundFile(int fileNumber);
signals:

};

#endif // SOUNDPLAYER_H
