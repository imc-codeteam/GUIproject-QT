#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 *  Constructor
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // create new widget and place it as a central widget
    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);

    // create tabs
    this->create_tabs();

    // create vertical layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(5);
    layout->addWidget(this->tabs);  // add generated tabs to the layout
    widget->setLayout(layout);

    // display status message
    QString message = tr("Welcome to RF3 editor");
    statusBar()->showMessage(message);

    // create menu actions
    this->create_actions();     // always execute this function before creating the menus

    // create drop-down menus
    this->create_menus();

    // set window parameters
    this->setWindowTitle("RF3 editor");     // set window label
    this->setMinimumSize(160, 160);         // set minimum size of the window
    this->resize(480, 320);                 // resize the windows
}


/*
 *  Create actions that will be executed when menu items are clicked
 */
void MainWindow::create_actions() {
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the program"));
    connect(exitAct, &QAction::triggered, this, &MainWindow::exit);
}

/*
 *  Create drop-down menus
 */
void MainWindow::create_menus() {
    // create file menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
//    fileMenu->addAction(openAct);
//    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
}

void MainWindow::create_tabs() {
    this->tabs = new QTabWidget();
    this->general_parameters_tab = new GeneralParametersTab();
    this->atomic_parameters_tab = new AtomicParametersTab();
    this->tabs->addTab(this->general_parameters_tab, tr("General parameters"));
    this->tabs->addTab(this->atomic_parameters_tab, tr("Atomic parameters"));
}

/*
 *  Destructor
 */
MainWindow::~MainWindow()
{
}

void MainWindow::newFile() {
    // do nothing
}

/*
 * Call to exit program
 */
void MainWindow::exit() {
    QApplication::quit();
}
