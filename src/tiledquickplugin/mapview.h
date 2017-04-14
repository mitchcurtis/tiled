/*
 * mapview.h
 * Copyright 2017, Mitch Curtis
 *
 * This file is part of Tiled Quick.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TILEDQUICK_MAPVIEW_H
#define TILEDQUICK_MAPVIEW_H

#include <QQuickItem>

namespace TiledQuick {

class MapItem;

/**
 * A declarative item that acts a viewport over a map.
 */
class MapView : public QQuickItem
{
    Q_OBJECT

    // The namespace qualification is required here. See: https://bugreports.qt.io/browse/QTBUG-15459
    Q_PROPERTY(TiledQuick::MapItem *mapItem READ mapItem WRITE setMapItem NOTIFY mapItemChanged)
    Q_PROPERTY(QRectF visibleArea READ visibleArea WRITE setVisibleArea NOTIFY visibleAreaChanged)

public:
    explicit MapView(QQuickItem *parent = 0);

    MapItem *mapItem() const;
    void setMapItem(MapItem *mapItem);

    QRectF visibleArea() const;
    void setVisibleArea(const QRectF &visibleArea);

    Q_INVOKABLE QPoint viewPosToMapPos(const QPoint &viewPos) const;

    void componentComplete();

signals:
    void mapItemChanged();
    void visibleAreaChanged();

private:
    MapItem *mMapItem;
    QRectF mVisibleArea;
};

} // namespace TiledQuick

#endif // TILEDQUICK_MAPVIEW_H
