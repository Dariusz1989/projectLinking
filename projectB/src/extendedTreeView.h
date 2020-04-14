//
// Created by Master on 13/04/2020.
//

#ifndef PROJECTA_EXTENDEDTREEVIEW_H
#define PROJECTA_EXTENDEDTREEVIEW_H

#include <extraItems/someEnums.h>
#include "projectA/src/treeView.h"


class extendedTreeView : public treeView {
    enumClassTest myClass;
public:
    extendedTreeView() { myClass = enumClassTest::testA; }
    ~extendedTreeView();
};


#endif //PROJECTA_EXTENDEDTREEVIEW_H
