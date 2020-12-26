#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>

class SoundPlayer : public QObject
{
    Q_OBJECT
public:
    SoundPlayer();
    bool playSoundFile(int fileNumber);
signals:

public slots:
};

#endif // SOUNDPLAYER_H
