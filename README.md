# Visual Studio で Google Test

## 参考サイト
[[C++] Google Test を使ってみた](http://www.mori-soft.com/2008-08-15-01-36-37/2009-08-02-15-37-17/192-c-google-test)  
[ビルドのコマンドとプロパティのマクロ](https://msdn.microsoft.com/ja-jp/library/c02as0cs.aspx)  

## 環境
* Visual Studio 2015
* gtest-1.7.0

## 手順
### プロジェクト作成
ファイル -> 新規作成 -> プロジェクト -> 名前欄に任意の名前を入力(ここでは"Sample"とした場合の説明) -> Win32 コンソールアプリケーション -> OK -> 次へ -> 完了

### gtestの準備
* 下記サイトから gtest-1.7.0.zip をダウンロード
[Downloads - googletest - Google C++ Testing Framework - Google Project Hosting](https://code.google.com/p/googletest/downloads/list)

* 解凍したフォルダの下記ソリューションファイルをダブルクリックし、Visual Studio を起動

        gtest-1.7.0\msvc\gtest-md.sln

* ソリューションのビルド(Release/Debugいずれも) を行い、下記のファイルが生成されることを確認

        gtest-1.7.0\msvc\gtest\Debug\gtestd.lib
        gtest-1.7.0\msvc\gtest\Debug\gtest_maind.lib

        gtest-1.7.0\msvc\gtest\Release\gtest.lib
        gtest-1.7.0\msvc\gtest\Release\gtest_main.lib

* 下記の通りフォルダ構成を整える

        Sample
        │  Sample.sdf
        │  Sample.sln
        │  README.md
        │
        │
        ├─Sample
        │  │  Sample.cpp
        │  │  Sample.vcxproj
        │  │  Sample.vcxproj.filters
        │  │  ReadMe.txt
        │  │  stdafx.cpp
        │  │  stdafx.h
        │  │  targetver.h
        │  │
        │  ├─include     // gtest-1.7.0\include をコピー
        │  │
        │  └─lib         // gtest-1.7.0\msvc\gtest 以下をコピー
        │      ├─Debug
        │      └─Release
        │
        └─ipch
            └─SAMPLE-5213e056
                    SAMPLE-c39dbf10.ipch

### INCLUDEディレクトリの追加
ソリューション右クリック -> プロパティ -> 構成プロパティ -> C/C++ -> [追加のインクルードディレクトリ] -> gtestのincludeディレクトリを追加  
※$(ProjectDir)を使用して追加した方がよい  

    例：$(ProjectDir)include

### libファイルのリンク設定
ソリューション右クリック -> プロパティ -> 構成プロパティ -> リンカー -> [追加のライブラリディレクトリ] -> gtestのlibのディレクトリを追加
$(Configuration)を利用して追加した方がよい  

    例：$(ProjectDir)lib\$(Configuration)

ソリューション右クリック -> プロパティ -> 構成プロパティ -> リンカー -> 入力 -> [追加の依存ファイル] ->  

    構成を[Release] に設定し、下記を追加
    gtest.lib
    gtest_main.lib

    構成を[Debug] に設定し、下記を追加
    gtestd.lib
    gtest_maind.lib

### ランタイムライブラリのリンク方法の指定を変更
ソリューション右クリック -> プロパティ -> 構成プロパティ -> C/C++ -> コード生成 -> [ランタイムライブラリ] ->  

    構成を[Release] に設定し、[マルチスレッド (/MT)] を設定

    構成を[Debug] に設定し、[マルチスレッド デバッグ (/MTd)] を設定


