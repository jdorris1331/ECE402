#include "..\include\ctrlmenubar.h"

CtrlMenuBar::CtrlMenuBar(QWidget *parent) : QMenuBar(parent)
{
    file = new QMenu(QString::fromStdString("&File"), this);
    fileNew = new QAction(QString::fromStdString("New"), file);
    fileOpen = new QAction(QString::fromStdString("Open"), file);
    fileAddToLib = new QAction(QString::fromStdString("Add to Library"), file);
    fileRecentFiles = new QMenu(QString::fromStdString("Recent Files"), file);
    fileSave = new QAction(QString::fromStdString("Save"), file);
    fileSaveAs = new QAction(QString::fromStdString("Save As"), file);
    fileUpToModCom = new QAction(QString::fromStdString("Upload to Model Commons"), file);
    filePrint = new QAction(QString::fromStdString("Print"), file);
    fileExport = new QMenu(QString::fromStdString("Export"), file);
    fileImport = new QMenu(QString::fromStdString("Import"), file);
    fileQuit = new QAction(QString::fromStdString("Quit"), file);

    edit = new QMenu(QString::fromStdString("&Edit"), this);
    editUndo = new QAction(QString::fromStdString("Undo"), edit);
    editRedo = new QAction(QString::fromStdString("Redo"), edit);
    editCut = new QAction(QString::fromStdString("Cut"), edit);
    editCopy = new QAction(QString::fromStdString("Copy"), edit);
    editPaste = new QAction(QString::fromStdString("Paste"), edit);
    editDelete = new QAction(QString::fromStdString("Delete"), edit);
    editSelectAll = new QAction(QString::fromStdString("Select All"), edit);
    editFind = new QAction(QString::fromStdString("Find..."), edit);
    editFindNext = new QAction(QString::fromStdString("Find Next"), edit);
    editShiftLeft = new QAction(QString::fromStdString("Shift Left"), edit);
    editShiftRight = new QAction(QString::fromStdString("Shift Right"), edit);
    editComment = new QAction(QString::fromStdString("Comment"), edit);
    editUncomment = new QAction(QString::fromStdString("Uncomment"), edit);
    editSnapToGrid = new QAction(QString::fromStdString("Snap to Grid"), edit);
    editSnapToGrid->setCheckable(true);
    editSnapToGrid->setChecked(true);

    tools = new QMenu(QString::fromStdString("&Tools"), this);
    toolsHalt = new QAction(QString::fromStdString("Halt"), tools);
    toolsGlobalMonitor = new QAction(QString::fromStdString("Global Monitor"), tools);
    toolsTurtleMonitor = new QAction(QString::fromStdString("Turtle Monitor"), tools);
    toolsPatchMonitor = new QAction(QString::fromStdString("Patch Monitor"), tools);
    toolsLinkMonitor = new QAction(QString::fromStdString("Link Monitor"), tools);
    toolsCloseAllAgentMonitors = new QAction(QString::fromStdString("Close All Agent Monitors"), tools);
    toolsHideCommandCenter = new QAction(QString::fromStdString("Hide Commmand Center"), tools);
    toolsThreedView = new QAction(QString::fromStdString("3D View"), tools);
    toolsColorSwatches = new QAction(QString::fromStdString("Color Swatches"), tools);
    toolsTurtleShapeEditor = new QAction(QString::fromStdString("Turtle Shape Editor"), tools);
    toolsLinkShapeEditor = new QAction(QString::fromStdString("Link Shape Editor"), tools);
    toolsBehaviorSpace = new QAction(QString::fromStdString("BehaviorSpace"), tools);
    toolsSystemDynamicsMonitor = new QAction(QString::fromStdString("System Dynamics Monitor"), tools);
    toolsHubNetClientEditor = new QAction(QString::fromStdString("HubNet Client Editor"), tools);
    toolsHubNetControlCenter = new QAction(QString::fromStdString("HubNet Control Center"), tools);

    zoom = new QMenu(QString::fromStdString("&Zoom"), this);
    zoomLarger = new QAction(QString::fromStdString("Larger"), zoom);
    zoomNormalSize = new QAction(QString::fromStdString("Normal Size"), zoom);
    zoomSmaller = new QAction(QString::fromStdString("Smaller"), zoom);

    help = new QMenu(QString::fromStdString("&Help"), this);
    helpPDEViewerHelp = new QAction(QString::fromStdString("PDEViewer Help"), help);

    this->addMenu(file);
    file->addAction(fileNew);
    file->addAction(fileOpen);
    file->addAction(fileAddToLib);
    file->addMenu(fileRecentFiles);
    file->addSeparator();
    file->addAction(fileSave);
    file->addAction(fileSaveAs);
    file->addAction(fileUpToModCom);
    file->addSeparator();
    file->addAction(filePrint);
    file->addSeparator();
    file->addMenu(fileExport);
    file->addSeparator();
    file->addMenu(fileImport);
    file->addSeparator();
    file->addAction(fileQuit);

    this->addMenu(edit);
    edit->addAction(editUndo);
    edit->addAction(editRedo);
    edit->addSeparator();
    edit->addAction(editCut);
    edit->addAction(editCopy);
    edit->addAction(editPaste);
    edit->addAction(editDelete);
    edit->addSeparator();
    edit->addAction(editSelectAll);
    edit->addSeparator();
    edit->addAction(editFind);
    edit->addAction(editFindNext);
    edit->addSeparator();
    edit->addAction(editShiftLeft);
    edit->addAction(editShiftRight);
    edit->addSeparator();
    edit->addAction(editComment);
    edit->addAction(editUncomment);
    edit->addSeparator();
    edit->addAction(editSnapToGrid);

    this->addMenu(tools);
    tools->addAction(toolsHalt);
    tools->addSeparator();
    tools->addAction(toolsGlobalMonitor);
    tools->addAction(toolsTurtleMonitor);
    tools->addAction(toolsPatchMonitor);
    tools->addAction(toolsLinkMonitor);
    tools->addAction(toolsCloseAllAgentMonitors);
    tools->addSeparator();
    tools->addAction(toolsHideCommandCenter);
    tools->addSeparator();
    tools->addAction(toolsThreedView);
    tools->addAction(toolsColorSwatches);
    tools->addAction(toolsTurtleShapeEditor);
    tools->addAction(toolsLinkShapeEditor);
    tools->addAction(toolsBehaviorSpace);
    tools->addAction(toolsSystemDynamicsMonitor);
    tools->addSeparator();
    tools->addAction(toolsHubNetClientEditor);
    tools->addAction(toolsHubNetControlCenter);

    this->addMenu(zoom);
    zoom->addAction(zoomLarger);
    zoom->addAction(zoomNormalSize);
    zoom->addAction(zoomSmaller);

    this->addMenu(help);
    help->addAction(helpPDEViewerHelp);
}
