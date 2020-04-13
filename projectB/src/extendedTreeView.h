//
// Created by Master on 13/04/2020.
//

#ifndef PROJECTA_EXTENDEDTREEVIEW_H
#define PROJECTA_EXTENDEDTREEVIEW_H


class extendedTreeView : public treeView {
    enumClassTest myClass;
public:
    extendedTreeView() { myClass = enumClasstest::testA; }
    ~extendedTreeView();
};


#endif //PROJECTA_EXTENDEDTREEVIEW_H
