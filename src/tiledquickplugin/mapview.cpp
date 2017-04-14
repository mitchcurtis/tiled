/*
 * mapview.cpp
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

#include "mapview.h"

#include "mapitem.h"
#include "maprenderer.h"

using namespace TiledQuick;

MapView::MapView(QQuickItem *parent) :
    QQuickItem(parent),
    mMapItem(nullptr)
{
}

MapItem *MapView::mapItem() const
{
    return mMapItem;
}

void MapView::setMapItem(MapItem *mapItem)
{
    if (mMapItem == mapItem)
        return;

    mMapItem = mapItem;
    emit mapItemChanged();
}

QRectF TiledQuick::MapView::visibleArea() const
{
    return mVisibleArea;
}

void MapView::setVisibleArea(const QRectF &visibleArea)
{
    mVisibleArea = visibleArea;
    if (mMapItem)
        mMapItem->setVisibleArea(visibleArea);
    emit visibleAreaChanged();
}

QPointF MapView::viewToTileCoords(qreal x, qreal y) const
{
    if (!mMapItem)
        return QPointF(x, y);

    const QPointF relativeToMap = mapToItem(mMapItem, QPointF(x, y));
    return mMapItem->renderer()->screenToTileCoords(relativeToMap);
}

QPointF MapView::tileToViewCoords(qreal x, qreal y) const
{
    if (!mMapItem)
        return QPointF(x, y);

    return mMapItem->renderer()->tileToScreenCoords(x, y);
}

QPointF MapView::viewToPixelCoords(qreal x, qreal y) const
{
    if (!mMapItem)
        return QPointF(x, y);

    return mMapItem->renderer()->screenToPixelCoords(x, y);
}

QPointF MapView::pixelToViewCoords(qreal x, qreal y) const
{
    if (!mMapItem)
        return QPointF(x, y);

    return mMapItem->renderer()->pixelToScreenCoords(x, y);
}

void MapView::componentComplete()
{
    QQuickItem::componentComplete();
//    if (mMap)
//        refresh();
}
