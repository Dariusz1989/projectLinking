//
// Created by Master on 13/04/2020.
//

#ifndef PROJECTA_TREEVIEW_H
#define PROJECTA_TREEVIEW_H

#include "QTreeView"
#include "entity.h"

class treeView : public QTreeView, public entity {
    Q_OBJECT

public:
    treeView();
    ~treeView();
};


#endif //PROJECTA_TREEVIEW_H
