object GTESTFrame: TGTESTFrame
  Left = 0
  Top = 0
  Width = 320
  Height = 240
  TabOrder = 0
  object HeadPanel: TPanel
    Left = 0
    Top = 0
    Width = 320
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
      Left = 166
      Top = 11
      Width = 41
      Height = 13
      Caption = 'Failures:'
    end
    object DurationLabel: TLabel
      Left = 238
      Top = 11
      Width = 33
      Height = 13
      Caption = 'Dauer:'
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
    Width = 320
    Height = 201
    Align = alClient
    TabOrder = 1
    object GTESTTreeView: TTreeView
      Left = 1
      Top = 1
      Width = 318
      Height = 199
      Align = alClient
      Indent = 19
      TabOrder = 0
      OnCustomDrawItem = GTESTTreeViewCustomDrawItem
      OnDblClick = GTESTTreeViewDblClick
    end
  end
end
