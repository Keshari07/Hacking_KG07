#pragma once

#include <QWidget>
#include "Bridge.h"

class QVBoxLayout;
class CPUSideBar;
class CPUDisassembly;
class CPUMultiDump;
class CPUStack;
class CPURegistersView;
class CPUInfoBox;
class CPUArgumentWidget;
class DisassemblerGraphView;
class MHDetachedWindow;

namespace Ui
{
    class CPUWidget;
}

class CPUWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CPUWidget(Architecture* architecture, QWidget* parent = nullptr);
    ~CPUWidget();
    Architecture* getArchitecture() const;

    // Misc
    void setDefaultDisposition();

    void saveWindowSettings();
    void loadWindowSettings();

    duint getSelectionVa();

    // Widget getters
    CPUSideBar* getSidebarWidget();
    CPUDisassembly* getDisasmWidget();
    DisassemblerGraphView* getGraphWidget();
    CPUMultiDump* getDumpWidget();
    CPUStack* getStackWidget();
    CPUInfoBox* getInfoBoxWidget();

public slots:
    void setDisasmFocus();
    void setGraphFocus();

protected:
    CPUSideBar* mSideBar;
    CPUDisassembly* mDisassembly;
    DisassemblerGraphView* mGraph;
    MHDetachedWindow* mGraphWindow;
    CPUMultiDump* mDump;
    CPUStack* mStack;
    CPURegistersView* mGeneralRegs;
    CPUInfoBox* mInfo;
    CPUArgumentWidget* mArgumentWidget;

    int disasMode;

private:
    Architecture* mArchitecture = nullptr;
    Ui::CPUWidget* ui;
    QByteArray mDisasmSidebarSplitterStatus;

private slots:
    void splitterMoved(int pos, int index);
    void attachGraph(QWidget* widget);
    void detachGraph();
};
