#ifndef DATASHOW_H
#define DATASHOW_H

#include <QAbstractItemModel>
#include <QBrush>
class DataShow : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit DataShow(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void UpdateData(double t,double o, double e);
 Qt::ItemFlags flags(const QModelIndex &index) const override;
private:
 QVector<double> temp;
    QVector<double> oxy;
    QVector<double> electricity;
    QStringList str;
};

#endif // DATASHOW_H
