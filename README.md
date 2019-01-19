# AuthWith - Qt Network Authorization wrapper class

`QDialog` ベースの吹き出し付きポップアップ

![画面](./docs/examples.png)

## 利用方法

環境例

|項目|内容|
|-|-|
|アプリケーション名|test|
|ライブラリフォルダ|`libs`|

### 1)ソースを取得

```console
# git submodule add git@github.com:sharkpp/qtauthwith.git libs/qtauthwith
# git submodule update
```

### 2a)ソースを取り込む

#### 2a.1)プロジェクトファイル(`.pro`)を変更

アプリケーションの `.pro` を変更する。

変更例

```diff
+ # You can also select to disable deprecated APIs only up to a certain version of Qt.
+ #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
+
+ include(./libs/qtauthwith/sources/authwith.pri)
+
+ SOURCES += \
+         main.cpp \
+         mainwindow.cpp \
```

### 2b)ライブラリを取り込む

#### 2b.1)ライブラリをビルド

`./libs/qtauthwith/authwith.pro` を `Qt Creator` で開きビルドする。

#### 2b.2)プロジェクトファイル(`.pro`)を変更

アプリケーションの `.pro` を変更する。

変更例

```diff
+ # You can also select to disable deprecated APIs only up to a certain version of Qt.
+ #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
+
+ AUTHWITH_USE_STATIC_LIB=1
+ include(./libs/qtauthwith/sources/authwith.pri)
+
+ SOURCES += \
+         main.cpp \
+         mainwindow.cpp \
```

### 3)`QDialog` ベースのクラスを作る。

### 4)ソースの変更

変更例

```cpp
  #include <QApplication>
  
  TaskTrayPopup::TaskTrayPopup(QWidget *parent)
-     : QDialog(parent)
+     : AuthWith(parent)
      , ui(new Ui::TaskTrayPopup)
  {
      ui->setupUi(this);
```

### 5)ヘッダの変更

変更例

```cpp
  #ifndef TASKTRAYPOPUP_H
  #define TASKTRAYPOPUP_H
  
+ #include "authwith.h"
  
  namespace Ui {
  class TaskTrayPopup;
  }
  
  class TaskTrayPopup
-         : public QDialog
  {
      Q_OBJECT
  
```

### 6)アプリケーションをビルド

完了

![画面](./docs/examples.png)

## クラスリファレンス

|定義|概要|
|-|-|
|`AythWith::AythWith(QWidget *parent = 0)`|コンストラクタ|

## 未実装

* 切り欠きの位置（右寄り/☑️中央/左寄り/なし）
* 吹き出しの角丸
* 非アクティブ化処理（まだ一部おかしい）

## ライセンス

© 2018 sharkpp

このアプリケーションは [MIT ライセンス](LICENSE.ja-JP) の下で提供されています。
