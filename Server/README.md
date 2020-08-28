macx {
    QMAKE_CXXFLAGS += -std=c++11

    _BOOST_PATH = /usr/local/Cellar/boost/1.73.0
    INCLUDEPATH += "$${_BOOST_PATH}/include/"
    INCLUDEPATH +=   "/usr/local/opt/openssl@1.1/include/"
    INCLUDEPATH += "/usr/local/Cellar/jsoncpp/1.9.3/include/"
    LIBS += -L$${_BOOST_PATH}/lib
    LIBS += -L/usr/local/opt/openssl@1.1/lib
    LIBS += -L/usr/local/Cellar/jsoncpp/1.9.3/lib
    ## Use only one of these:
    LIBS += -lboost_chrono-mt -lboost_system  -lssl -lcrypto -ljsoncpp# using dynamic lib (not sure if you need that "-mt" at the end or not)
    #LIBS += $${_BOOST_PATH}/lib/libboost_chrono-mt.a # using static lib
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql