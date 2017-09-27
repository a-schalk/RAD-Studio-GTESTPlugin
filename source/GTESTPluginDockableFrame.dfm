object GTESTFrame: TGTESTFrame
  Left = 0
  Top = 0
  Width = 471
  Height = 240
  TabOrder = 0
  object HeadPanel: TPanel
    Left = 0
    Top = 0
    Width = 471
    Height = 39
    Align = alTop
    TabOrder = 0
    object TestsLabel: TLabel
      Left = 102
      Top = 11
      Width = 30
      Height = 13
      Caption = 'Tests:'
    end
    object FailureLabel: TLabel
      Left = 158
      Top = 11
      Width = 41
      Height = 13
      Caption = 'Failures:'
    end
    object DurationLabel: TLabel
      Left = 352
      Top = 11
      Width = 26
      Height = 13
      Caption = 'Time:'
    end
    object ErrorsLabel: TLabel
      Left = 222
      Top = 11
      Width = 33
      Height = 13
      Caption = 'Errors:'
    end
    object DisabledLabel: TLabel
      Left = 278
      Top = 11
      Width = 44
      Height = 13
      Caption = 'Disabled:'
    end
    object StartButton: TButton
      Left = 8
      Top = 6
      Width = 75
      Height = 26
      Caption = 'Start'
      TabOrder = 0
      OnClick = StartButtonClick
    end
  end
  object BodyPanel: TPanel
    Left = 0
    Top = 39
    Width = 471
    Height = 201
    Align = alClient
    TabOrder = 1
    object GTESTTreeView: TTreeView
      Left = 1
      Top = 1
      Width = 469
      Height = 199
      Align = alClient
      Indent = 19
      TabOrder = 0
      OnCustomDrawItem = GTESTTreeViewCustomDrawItem
      OnDblClick = GTESTTreeViewDblClick
    end
  end
end
