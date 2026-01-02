/**
 * LRCScrollKeyFilter.h
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLLKEYFILTER_H
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLLKEYFILTER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

namespace lmms
{
    namespace gui
    {
        class LRCScrollKeyFilter : public QObject
        {
            Q_OBJECT // Place at the top of the class

        public:
            explicit LRCScrollKeyFilter(QObject* parent = nullptr) : QObject(parent){}

        protected:
            bool eventFilter(QObject* obj, QEvent* event) override;
        };
    }
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLLKEYFILTER_H