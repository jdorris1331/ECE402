#ifndef CTRLMENUBAR_H
#define CTRLMENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class CtrlMenuBar : public QMenuBar
{
public:
    CtrlMenuBar(QWidget *parent = 0);

private:
    QMenu *file, *edit, *tools, *zoom, *help;

    QAction *fileNew, *fileOpen, *fileAddToLib,
            *fileSave, *fileSaveAs, *fileUpToModCom,
            *filePrint, *fileQuit;
    QMenu *fileRecentFiles, *fileExport, *fileImport;

    QAction *editUndo, *editRedo, *editCut, *editCopy, *editPaste, *editDelete,
            *editSelectAll, *editFind, *editFindNext, *editShiftLeft, *editShiftRight,
            *editComment, *editUncomment, *editSnapToGrid;

    QAction *toolsHalt, *toolsGlobalMonitor, *toolsTurtleMonitor, *toolsPatchMonitor,
            *toolsLinkMonitor, *toolsCloseAllAgentMonitors, *toolsHideCommandCenter,
            *toolsThreedView, *toolsColorSwatches, *toolsTurtleShapeEditor,
            *toolsLinkShapeEditor, *toolsBehaviorSpace, *toolsSystemDynamicsMonitor,
            *toolsHubNetClientEditor, *toolsHubNetControlCenter;

    QAction *zoomLarger, *zoomNormalSize, *zoomSmaller;

    QAction *helpPDEViewerHelp;
};

#endif // CTRLMENUBAR_H
