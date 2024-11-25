#include "datashow.h"

DataShow::DataShow(QObject *parent)
    : QAbstractItemModel(parent)
{
    temp.push_back(-1);
    oxy.push_back(-1);
    electricity.push_back(-1);
    str<<"温度"<<"溶解氧"<<"电力值";
}

QVariant DataShow::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    if(orientation==Qt::Horizontal){
        return "当前值";
    }else{
        return QVariant(str[section]);
    }
}

QModelIndex DataShow::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
    if(!parent.isValid()&&row>=0&&row<3&&column>=0&&column<2)
        return createIndex(row,column);
    return QModelIndex();
}

QModelIndex DataShow::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    Q_UNUSED(index);
    return QModelIndex(); // 没有父项
}

int DataShow::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 3;
    // FIXME: Implement me!
}

int DataShow::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 1;
    // FIXME: Implement me!
}

QVariant DataShow::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    // FIXME: Implement me!
    int row=index.row();
    if(role ==Qt::DisplayRole){
        switch (row) {
        case 0:
            return temp.back();
            break;
        case 1:
            return oxy.back();
            break;
        case 2:
            return electricity.back();
            break;
        default:
            break;
        }
    }
    if (role == Qt::BackgroundRole) {
        switch (row) {
        case 0:
            return temp.back()<=20?QBrush(Qt::red):QBrush(Qt::green);
            break;
        case 1:
            return oxy.back()<=30?QBrush(Qt::red):QBrush(Qt::green);
            break;
        case 2:
            return electricity.back()<2000||electricity.back()>15000?QBrush(Qt::red):QBrush(Qt::green);
            break;
        default:
            break;
        }
    }
    return QVariant();
}

void DataShow::UpdateData(double t, double o, double e)
{
    beginResetModel();
    temp.push_back(t);
    oxy.push_back(o);
    electricity.push_back(e);
    endResetModel();
}
Qt::ItemFlags DataShow::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    // 允许单元格被选中
    return QAbstractItemModel::flags(index) | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
