#include <QCoreApplication>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QtSql/QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Initialize WebSocket server
    QWebSocketServer webSocketServer(QStringLiteral("SoundScrolls WebSocket Server"), QWebSocketServer::NonSecureMode);
    if (webSocketServer.listen(QHostAddress::Any, 12345))
    {
        qDebug() << "WebSocket Server listening on port" << 12345;
    }

    // Initialize SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("soundscrolls");

    if (!db.open())
    {
        qDebug() << "Could not open SQLite database.";
    }
    else
    {
        qDebug() << "SQLite database opened.";
    }

    // TODO: Implement folder watching, REST API, etc.

    return app.exec();
}
