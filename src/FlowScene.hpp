#ifndef _FLOW_SCENE_HPP_
#define _FLOW_SCENE_HPP_

#include <QtCore/QMap>
#include <QtCore/QUuid>

#include <QtWidgets/QGraphicsScene>

#include <tuple>

#include "Connection.hpp"

class FlowItemInterface;
class FlowItem;

class FlowScene : public QGraphicsScene
{
public:
  static
  FlowScene&instance();

public:
  QUuid createConnection(std::pair<QUuid, int> address,
                         Connection::EndType draggingEnd);

  QUuid createFlowItem();

public:

  Connection* getConnection(QUuid id) const;

  FlowItem* getFlowItem(QUuid id) const;

  /// Remembers the connection currently is being dragged
  void setDraggingConnection(QUuid id, Connection::EndType dragging);

  bool isDraggingConnection();

  /// Sets currently dragging connection to empty value
  void clearDraggingConnection();

private:
  FlowScene();

private:
  QMap<QString, FlowItemInterface*> _registeredInterfaces;

  static FlowScene* _instance;

  QMap<QUuid, Connection*> _connections;
  QMap<QUuid, FlowItem*>   _flowItems;

  QUuid _draggingConnectionID;
  Connection::EndType _dragging;
};

#endif //  _FLOW_SCENE_HPP_